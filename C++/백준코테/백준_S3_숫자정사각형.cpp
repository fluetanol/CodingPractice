// 문제번호 : 1051번
// 숫자정사각형
// 푼 시간 : 20분
// 알고리즘 분류 : 브루트포스

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    string *s = new string[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    int max = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // cout << s[i][j];
            for (int h = 0, k = 0; i + h < n && j + k < m; h++, k++)
            {

                if (s[i][j] == s[i + h][j] && s[i][j] == s[i][j + k] && s[i][j] == s[i + h][j + k])
                {

                    if (max < (h + 1) * (k + 1))
                        max = (h + 1) * (k + 1);
                }
            }
        }
    }

    cout << max;
}


/*
    가능한 모든 정사각형의 구석탱이를 추적하면 되는 문제이므로 문제설명은 생략

*/