#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
int n, k;

bool is_range(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < k;
}

bool bfs(pair<int, int> p, vector<vector<int>> &map, int size)
{
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(k));
    visited[p.first][p.second] = true;
    int count = 0;
    q.push(p);

    while (!q.empty())
    {
        pair<int, int> new_p = q.front();
        q.pop();
        count++;

        int r = new_p.first;
        int c = new_p.second;

        for (int i = 0; i < 4; ++i)
        {
            int ddr = r + dr[i];
            int ddc = c + dc[i];

            if (is_range(ddr, ddc) && !visited[ddr][ddc] && map[ddr][ddc] != 0)
            {
                visited[ddr][ddc] = true;
                q.push({ddr, ddc});
            }
        }
    }

    // 여전히 하나로 뭉쳐있음
    if (count == size)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void melt(queue<pair<int, int>> &ice_pos, vector<vector<int>> &map)
{

    int size = ice_pos.size();
    vector<vector<bool>> visited(n, vector<bool>(k));

    for (int i = 0; i < size; ++i)
    {
        pair<int, int> p = ice_pos.front();
        ice_pos.pop();

        // cout << p.first << " " << p.second << endl;

        int r = p.first;
        int c = p.second;

        for (int j = 0; j < 4; ++j)
        {
            int ddr = r + dr[j];
            int ddc = c + dc[j];

            if (is_range(ddr, ddc) && map[ddr][ddc] == 0 && !visited[ddr][ddc])
            {
                map[r][c] = max(map[r][c] - 1, 0);
            }
            if (map[r][c] == 0)
                break;
        }

        visited[r][c] = true;

        if (map[r][c] > 0)
            ice_pos.push(p);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(k));
    queue<pair<int, int>> ice_pos;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < k; ++j)
        {
            cin >> v[i][j];
            if (v[i][j] > 0)
            {
                ice_pos.push({i, j});
            }
        }
    }

    int year = 0;

    // 하나로 뭉쳐있으며, 큐에 여전히 빙산이 있다면
    while (!ice_pos.empty() && bfs(ice_pos.front(), v, ice_pos.size()))
    {
        year++;

        melt(ice_pos, v);

        // 더 이상 녹을 빙하가 없음
        int size = ice_pos.size();
        if (size == 0)
        {
            year = 0;
            break;
        }
    }

    // 쪼개졌거나 더이상 녹을 빙하도 없는 경우
    cout << year;
}
