// 문제번호 : 1012번
// 유기농배추
// 푼 시간 : 30분
// 알고리즘 분류 : DFS, 그래프 탐색

#include <iostream>
#include <vector>


using namespace std;

void DFS(int x, int y, vector<vector<int>> &v, vector<vector<int>> &c, int depth, int &count)
{
    if (x < 0 || y < 0 || x >= v.size() || y >= v[0].size())
        return;

    else if (v[x][y] == 0 && depth > 0)
    {
        return;
    }

    else if (c[x][y] == 1)
    {
        return;
    }

    if (depth == 0)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (c[i][j] == 0 && v[i][j] == 1)
                {
                    c[i][j] = 1;
                    DFS(i - 1, j, v, c, depth + 1, count);
                    DFS(i, j - 1, v, c, depth + 1, count);
                    DFS(i + 1, j, v, c, depth + 1, count);
                    DFS(i, j + 1, v, c, depth + 1, count);

                    count++;
                }
            }
        }
    }
    else
    {
        c[x][y] = 1;
        DFS(x - 1, y, v, c, depth + 1, count);
        DFS(x, y - 1, v, c, depth + 1, count);
        DFS(x + 1, y, v, c, depth + 1, count);
        DFS(x, y + 1, v, c, depth + 1, count);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<int>> v(m);
        for (int i = 0; i < m; i++)
            v[i].resize(n);
        vector<vector<int>> check(v);

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            v[x][y] = 1;
        }
        int count = 0;

        DFS(0, 0, v, check, 0, count);

        cout << count << endl;
    }
}


/*
    설명 할 게 딱히 없고 DFS로 유기농배추가 모여있는 클러스터의 갯수를 찾으면 되는 문제
    잔실수가 많아서 30분 살짝 넘게 걸렸는데 없었으면 20분컷 냈을듯


*/
