// 문제번호 : 1080
// 행렬 
// 푼 시간 : 2일 (답안/힌트 확인함)
// 알고리즘 분류 : 그리디

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

void checkSame(string *&a, string *&b, int n, int m, int &count)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                count = -1;
                return;
            }
        }
    }
}

void flip(int i, int j, string *&a, string *&b)
{
    for (int k = i; k <= i + 2; k++)
    {
        for (int l = j; l <= j + 2; l++)
        {
            if (a[k][l] == '1')
                a[k][l] = '0';
            else
                a[k][l] = '1';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    string *a = new string[n];
    string *b = new string[n];

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int count = 0;

    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            if (a[i][j] != b[i][j])
            {
                count++;
                flip(i, j, a, b);
            }
        }
    }
    checkSame(a, b, n, m, count);
    cout << count;
}


// 이 문제는 s1주제에 문제 풀이를 생각하는 과정이 정말 까다로운데
// 아직도 제대로 이해 못했으니 추후에 노션에 따로 정리해두겠음
// 그리디 알고리즘이라는 분류를 알고도 왜 이게 그리디로 풀리는 문제인지 부터 이해가 안됨.

// 아 참고로 이제부터 푸는데에 너무 오래걸렸거나 답안지를 확인한 문제들은 티어명 뒤에 +를 남겨놓음