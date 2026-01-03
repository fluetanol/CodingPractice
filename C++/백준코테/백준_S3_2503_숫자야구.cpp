#include <iostream>
#include <vector>
#include <string>
#include <array>

using namespace std;

vector<array<int, 3>> v;
int ans;

bool baseball(int val)
{

    bool flag = true;

    // 모든 answer와 숫자 야구 비교
    for (int i = 0; i < v.size(); ++i)
    {
        int comp_val = v[i][0];
        int comp_stk = v[i][1];
        int comp_ball = v[i][2];

        string s_val = to_string(val);
        string s_comp_val = to_string(comp_val);
        int cnt_stk = 0;
        int cnt_ball = 0;

        for (int i = 0; i < 3; ++i)
        {
            char c_val = s_val[i];
            for (int j = 0; j < 3; ++j)
            {
                char c_comp_val = s_comp_val[j];
                if (c_val == c_comp_val && i == j)
                {
                    cnt_stk++;
                }
                else if (c_val == c_comp_val && i != j)
                {
                    cnt_ball++;
                }
            }
        }

        if (comp_stk != cnt_stk || comp_ball != cnt_ball)
        {
            flag = false;
            break;
        }
    }

    return flag;
}

void comb(int value, int multiple, vector<short> &valid_num)
{

    if (multiple > 100)
    {
        ans = baseball(value) ? ans + 1 : ans;
        return;
    }

    for (int i = 1; i < valid_num.size(); ++i)
    {
        if (valid_num[i] == 0)
        {
            valid_num[i] = 1;
            comb(value + i * multiple, multiple * 10, valid_num);
            valid_num[i] = 0;
        }
    }
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int arr[3];

        cin >> arr[0] >> arr[1] >> arr[2];

        // edge case
        if (arr[1] == 3)
        {
            cout << 1;
            return 0;
        }

        v.push_back({arr[0], arr[1], arr[2]});
    }

    vector<short> valid_num(10);
    comb(0, 1, valid_num);
    cout << ans;
}

/*
    아이디어
    질문을 토대로 가능한 숫자를 선별하지말고,
    답이 될 수 있는 범위를 하나하나 brute force 해서 맞는 게 몇 개인지 찾아내자

    범위가 작고, 질문의 수도 작기 때문에 가능한 방법이라고 생각한다.

    문제의 관점을 역으로 생각하는 것을 자주 해봐야 한다고 생각한다.



    참고로 이 문제는 숫자 야구의 케이스에 따라 전처리 후 가능한 숫자 범위를 좁히는 것도 가능하다.
    내가 찾아낸 아래 최적화 케이스를 참고하자.
    난 귀찮아서 구현 안함


    최적화 케이스

    0스 0볼 => 그 세 가지 수는 절대 아니다. 1~9에서 그 세 수는 제외시킨다
    3스 0볼 => 정답이다

    2스 1볼
    1스 2볼 => 그 세 가지 수로만 처리 가능하다, 따라서 그 세 가지 수만 조합시켜서 체크해도 된다.
    0스 3볼


*/