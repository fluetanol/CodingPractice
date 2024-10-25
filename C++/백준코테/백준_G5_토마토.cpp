// 문제번호 : 7576
// 토마토
// 푼 시간 : 50분
// 알고리즘 분류 : bfs(너비 우선 탐색)

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int bfs(vector<vector<int>> &v, queue<pair<int, int>> &q, int size)
{
    int count = -1;


    while (!q.empty())
    {
        vector<pair<int, int>> cordArray;
        cordArray.reserve(100);

        while (!q.empty())
        {
            pair<int, int> cord = q.front();
            cordArray.push_back(cord);
            q.pop();
        }

        for (auto cord : cordArray)
        {
            if (cord.first + 1 < v.size() && !v[cord.first + 1][cord.second])
            {
                v[cord.first + 1][cord.second] = 1;
                q.push(make_pair(cord.first + 1, cord.second));
                size--;
            }

            if (cord.first - 1 >= 0 && !v[cord.first - 1][cord.second])
            {
                v[cord.first - 1][cord.second] = 1;
                q.push(make_pair(cord.first - 1, cord.second));
                size--;
            }

            if (cord.second + 1 < v[0].size() && !v[cord.first][cord.second + 1])
            {
                v[cord.first][cord.second + 1] = 1;
                q.push(make_pair(cord.first, cord.second + 1));
                size--;
            }

            if (cord.second - 1 >= 0 && !v[cord.first][cord.second - 1])
            {
                v[cord.first][cord.second - 1] = 1;
                q.push(make_pair(cord.first, cord.second - 1));
                size--;
            }
        }

        count++;
    }

    if (size > 0)
        return -1;
    else
        return count;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(n);
    queue<pair<int, int>> q;

    int size = m * n;

    for (int i = 0; i < n; i++)
    {
        v[i].resize(m);
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1)
            {
                q.push(make_pair(i, j));
                size--;
            }
            else if (v[i][j] == -1)
            {
                size--;
            }
        }
    }

    cout << bfs(v, q, size) << endl;
}


/*
    1이 있는 위치를 기록해두고(좌표를 기록해뒀음)
    상하좌우로 퍼져나가는 방식으로 토마토가 익는데 걸리는 시간을 구하는 문제.

    배열이니까 인덱스 범위 체크 잘하고, -1이나 1이 있는 곳은 더 이상 둘러보지 않도록 조건문만 신경 써주면
    쉽게 풀리는 문제였다.

    참고로 상하좌우 체크에 대한 코드를 좀 더 깔끔하게 하려면 아래 방법을 사용하라.
*/

bool isRange(int dx, int dy, vector<vector<int>> &v)
{
    return dx >= 0 && dy >= 0 && dx < v.size() && dy < v[0].size();
}

int bfs(vector<vector<int>> &v, queue<pair<int, int>> &q, int size)
{
    int count = -1;

    int deltax[] = {1, -1, 0, 0};
    int deltay[] = {0, 0, 1, -1};

    while (!q.empty())
    {
        vector<pair<int, int>> cordArray;
        cordArray.reserve(100);
        while (!q.empty())
        {
            pair<int, int> cord = q.front();
            cordArray.push_back(cord);
            q.pop();
        }

        for (auto cord : cordArray)
        {
            for (int i = 0; i < 4; i++)
            {
                int dx = cord.first + deltax[i];
                int dy = cord.second + deltay[i];

                if (isRange(dx, dy, v) && !v[dx][dy])
                {
                    v[dx][dy] = 1;
                    q.push(make_pair(dx, dy));
                    size--;
                }
            }
        }
        count++;
    }

    if (size > 0)
        return -1;
    else
        return count;
}