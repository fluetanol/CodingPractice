// 문제번호 : 1032번
// 명령 프롬프트
// 푼 시간 : 10분
// 알고리즘 분류 : 문자열, 구현
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)

int main()
{
    int n;
    cin >> n;

    vector<string> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    string answer = "";
    for (int i = 0; i < v[0].size(); i++)
    {
        char c = v[0][i];
        bool isSame = true;
        for (int j = 0; j < n; j++)
        {
            if (c != v[j][i])
            {
                isSame = false;
                break;
            }
        }
        if (isSame)
            answer += c;
        else
            answer += "?";
    }

    cout << answer;
    return 0;
}