// 문제번호 : 2468번
// 안전영역
// 푼 시간 : 30분
// 알고리즘 분류 : 브루트포스, DFS, BFS



// DFS로 푸는 방법
#include <iostream>
#include <vector>

using namespace std;

void DFS(vector<vector<int>> &v, vector<vector<bool>> &visited, int h, int area, int i, int j)
{
    if (v[i][j] <= h)
        return;
    else if (visited[i][j] != 0)
        return;

    visited[i][j] = 1;

    if (i < v.size() - 1)
        DFS(v, visited, h, area, i + 1, j);
    if (i > 0)
        DFS(v, visited, h, area, i - 1, j);
    if (j < v.size() - 1)
        DFS(v, visited, h, area, i, j + 1);
    if (j > 0)
        DFS(v, visited, h, area, i, j - 1);
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    vector<vector<int>> v(k);
    vector<vector<bool>> visited(k);
    for (int i = 0; i < k; i++)
    {
        v[i].resize(k);
        visited[i].resize(k);
    }

    int max = -1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            if (max < t)
                max = t;
            v[i][j] = t;
        }
    }

    int maxarea = -1;
    for (int h = 0; h <= max; h++)
    {
        int area = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (v[i][j] > h && visited[i][j] == 0)
                {
                    area++;
                    DFS(v, visited, h, area, i, j);
                }
            }
        }

        if (maxarea < area)
        {
            maxarea = area;
        }
        for (int i = 0; i < k; i++)
        {
            vector<bool> visit(k, {0});
            visited[i] = visit;
        }
    }

    cout << maxarea << endl;
}



//bfs로 풀기

#include <iostream>
#include <queue>

using namespace std;

void BFS(int **&v, bool **&visited, queue<pair<int, int>> &q, int h, int size)
{
    while (!q.empty())
    {
        auto pair = q.front();
        int x = pair.first;
        int y = pair.second;
        q.pop();

        if (x > 0 && visited[x - 1][y] == 0 && v[x - 1][y] > h)
        {
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = 1;
        }
        if (y > 0 && visited[x][y - 1] == 0 && v[x][y - 1] > h)
        {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = 1;
        }
        if (x < size - 1 && visited[x + 1][y] == 0 && v[x + 1][y] > h)
        {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = 1;
        }
        if (y < size - 1 && visited[x][y + 1] == 0 && v[x][y + 1] > h)
        {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;

    int **v = new int *[k];
    bool **visited = new bool *[k];
    for (int i = 0; i < k; i++)
    {
        v[i] = new int[k]{0};
        visited[i] = new bool[k]{0};
    }

    int max = -1;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int t;
            cin >> t;
            if (max < t)
                max = t;
            v[i][j] = t;
        }
    }

    int maxarea = -1;
    queue<pair<int, int>> q;
    for (int h = 0; h <= max; h++)
    {
        int area = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if (v[i][j] > h && visited[i][j] == 0)
                {
                    area++;
                    q.push(make_pair(i, j));
                    BFS(v, visited, q, h, k);
                }
            }
        }

        if (maxarea < area)
        {
            maxarea = area;
        }
        for (int i = 0; i < k; i++)
        {
            delete[] visited[i];
            visited[i] = new bool[k]{0};
        }
    }

    cout << maxarea << endl;
}


/*
    참고로 속도 성능은 bfs, 공간적 성능은 dfs가 우위로 나왔다

    특히 bfs는 visited의 체크 위치에 따라 순간적으로 큐에 들어가는 노드의 갯수가 달라져서
    메모리 초과까지 떴었다...

*/