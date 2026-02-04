#include <iostream>
#include <queue>
#include <climits>

using namespace std;

/*
    진짜 간단함
    적록색약이 아닌 경우는 R!=G로 취급하고
    적록색약인 경우 R==G로 취급해서 영역 계산하면 됨
    탐색 방향은 사방 탐색이며, visited로 중복 점검 못하게 막으면 됨
*/

string map[101];
bool visited[101][101] = {false};

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool is_range(int i, int j, int n)
{
    return i >= 0 && j >= 0 && i < n && j < n;
}

void enableRedGreen(int i, int j, int n)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    char value = map[i][j];

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int pi = p.first;
        int pj = p.second;

        for (int k = 0; k < 4; ++k)
        {
            int ddx = pi + dx[k];
            int ddy = pj + dy[k];

            if (is_range(ddx, ddy, n) && !visited[ddx][ddy] && value == map[ddx][ddy])
            {
                q.push({ddx, ddy});
                visited[ddx][ddy] = true;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> map[i];

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                enableRedGreen(i, j, n);
                count++;
            }
        }
    }

    cout << count << "\n";

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (map[i][j] == 'G')
                map[i][j] = 'R';
            visited[i][j] = false;
        }
    }

    count = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!visited[i][j])
            {
                visited[i][j] = true;
                enableRedGreen(i, j, n);
                count++;
            }
        }
    }

    cout << count;
}
