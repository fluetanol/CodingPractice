// 문제번호 : 9935번
// 문자열 폭발
// 푼 시간 : 1시간
// 알고리즘 분류 : 문자열, 스택

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s1;
    string s2;
    cin >> s1 >> s2;

    vector<char> v;
    v.reserve(s1.size());

    int i = v.size();
    int idx = 0;
    while (idx <= s1.size())
    {
        int count = 0;

        for (int j = 0; j < s2.size(); j++)
        {
            if (v.size() < s2.size())
                break;
            else if (v[v.size() - 1 - j] == s2[s2.size() - 1 - j])
            {
                count++;
            }
            else
            {
                count = 0;
                break;
            }
        }

        if (count == s2.size())
        {
            v.erase(v.end() - s2.size(), v.end());
        }
        if (idx < s1.size())
            v.push_back(s1[idx]);
        idx++;
    }

    if (v.size() == 0)
    {
        cout << "FRULA";
    }
    else
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
        }
    }
}


/*
    이 문제의 풀이는 후위순위를 하는 것과 비슷하다.
    어떤 문자를 스택에 넣으려 할 떄, 그 문자가 숫자면 그냥 넣지만,
    그게 아니라 연산자면 즉시 스택에 있는 두 문자를 꺼내서 연산을 한 후에
    그 결과를 다시 스택에 넣는다.

    비슷한 느낌으로, 문자열을 받을 때마다 스택에 넣어주는데,
    스택의 top부터 연속된 문자열이 폭발 문자열과 일치하는지 확인한다.
    그리고 일치하면 폭발 문자열은 pop으로 없애준다.
    "폭발 조건"이 일종의 연산자와 같은 역할을 하는 문제인 것이다...




    참고로 위 문제를 find()함수를 이용해서 풀면 시간초과이다.
    find는 O(n)이기 때문에, 문자열 길이가 1,000,000이면 1,000,000^2이 되어버린다.
    간결한 함수 하나인줄 알았지만, 내부 동작은 상당히 무거운것.
*/