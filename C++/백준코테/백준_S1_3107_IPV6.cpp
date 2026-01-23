#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
    규칙이 이러함

    1. 무조건 네 자리씩 뭉쳐 있어야함
    2. 0000 이 연속 그룹으로 이루어진 경우 :: 로 치환이 가능함
    1234:0000:0000:0000:0567 -> 1234::567
    다만 이러한 케이스는 단 한번만 존재한다.
    3. 앞자리에 0이 있는 경우 일부를 생략하거나 0 모두를 생략해도 됨
    4. 32자리여야 하니까 8개의 그룹으로 이루어짐.


    1단계 -> 4자리가 아닌 케이스를 복구 시키기
    4자리가 아닌 경우는 그냥 0만 앞에 채워넣으면 된다.

    2001:db8:85a3::8a2e:370:7334 라면
    2001:0db8:85a3::8a2e:0370:7334 가 된다.

    2 단계 -> ::가 있다면, 지금까지 몇개의 뭉치가 성공적으로 만들어졌는지 확인해보기
    1단계 작업으로 인해 4개씩 묶인게 6개인걸 볼 수 있다.
    8-6=2, 즉 2개의 그룹이 부족하다.

    2001:0db8:85a3:  0000:0000 :8a2e:0370:7334
*/

vector<string> split(string s)
{
    istringstream iss(s);
    string split_s;
    vector<string> v_split;

    while (getline(iss, split_s, ':'))
    {
        v_split.push_back(split_s);
    }

    return v_split;
}

void IPV6(string s)
{
    vector<string> v_split = split(s);
    stringstream ans_ss;
    stringstream ss;

    bool isEmpty = false;
    int count = 0;
    int empty_idx = -1;
    // 0 단순 채워넣기
    for (int i = 0; i < v_split.size(); ++i)
    {

        if (v_split[i].size() > 0 && v_split[i].size() <= 4)
        {
            for (int j = 0; j < 4 - v_split[i].size(); ++j)
            {
                ss << "0";
            }
            ss << v_split[i];
            v_split[i] = ss.str();
            ss.str("");
            ss.clear();
            count++;
        }
        else if (v_split[i].size() == 0 && isEmpty == false)
        {
            empty_idx = i;
            isEmpty = true;
        }
    }

    stringstream zero_ss;
    if (isEmpty)
    {
        int need_count = 8 - count;
        for (int i = 0; i < need_count; ++i)
        {
            zero_ss << "0000";
            if (i != need_count - 1)
            {
                zero_ss << ":";
            }
        }
    }

    stringstream sum_ss;

    for (int i = 0; i < v_split.size(); ++i)
    {

        if (i == empty_idx)
        {
            ans_ss << sum_ss.str() << zero_ss.str();
            if (empty_idx > 0 && empty_idx < v_split.size() - 1)
            {
                ans_ss << ":";
            }
            sum_ss.str("");
            sum_ss.clear();
        }
        else
        {
            sum_ss << v_split[i];
            if (i < v_split.size() - 1)
                sum_ss << ":";
        }
    }

    ans_ss << sum_ss.str();

    cout << ans_ss.str() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    IPV6(s);
}
