// 문제번호 : 2178번
// 미로 탐색
// 푼 시간 : 30분
// 알고리즘 분류 : BFS

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<string> &v, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    int count = 1;

    while (!q.empty())
    {
        int size = q.size();
        bool isDestination = false;

        for (int i = 0; i < size; i++)
        {
            auto xy = q.front();
            int x = xy.first;
            int y = xy.second;
            if (x == v.size() - 1 && y == v[0].size() - 1)
            {
                isDestination = true;
                break;
            }

            if (x < v.size() - 1 && v[x + 1][y] == '1' && visited[x + 1][y] == false)
            {
                visited[x + 1][y] = true;
                q.push(make_pair(x + 1, y));
            }
            if (y < v[0].size() - 1 && v[x][y + 1] == '1' && visited[x][y + 1] == false)
            {
                visited[x][y + 1] = true;
                q.push(make_pair(x, y + 1));
            }
            if (x > 0 && v[x - 1][y] == '1' && visited[x - 1][y] == false)
            {
                visited[x - 1][y] = true;
                q.push(make_pair(x - 1, y));
            }
            if (y > 0 && v[x][y - 1] == '1' && visited[x][y - 1] == false)
            {
                visited[x][y - 1] = true;
                q.push(make_pair(x, y - 1));
            }

            q.pop();
        }

        if (isDestination)
            break;

        count++;
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    vector<vector<bool>> visited(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        visited[i].resize(m);
    }

    cout << BFS(v, visited) << endl;
}

/*
    참고로 DFS는 조건문을 엄청 까다롭게 짤게 아니면
    시간도 오래걸리고 구현도 어려워짐

*/