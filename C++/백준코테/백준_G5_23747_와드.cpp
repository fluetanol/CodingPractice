#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int r, c;
pair<int, int> p_dir[26];
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

bool is_range(int ddr, int ddc)
{
    return ddr >= 0 && ddc >= 0 && ddr < r && ddc < c;
}

void bfs(vector<string> &v, vector<vector<char>> &sight, int sr, int sc)
{
    queue<pair<int, int>> q;
    q.push({sr, sc});

    char area = v[sr][sc];

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        sr = p.first;
        sc = p.second;

        for (int i = 0; i < 4; ++i)
        {
            int ddr = sr + dr[i];
            int ddc = sc + dc[i];

            if (is_range(ddr, ddc) && area == v[ddr][ddc] && sight[ddr][ddc] == '#')
            {
                sight[ddr][ddc] = '.';
                q.push({ddr, ddc});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    p_dir['U' - 'A'] = {-1, 0};
    p_dir['D' - 'A'] = {1, 0};
    p_dir['L' - 'A'] = {0, -1};
    p_dir['R' - 'A'] = {0, 1};
    p_dir['W' - 'A'] = {0, 0};

    cin >> r >> c;

    vector<string> v(r);
    vector<vector<char>> sight(r, vector<char>(c, '#'));

    for (int i = 0; i < r; ++i)
    {
        cin >> v[i];
    }

    int sr, sc;
    cin >> sr >> sc;
    sr--;
    sc--;

    string cmd;
    cin >> cmd;

    for (int i = 0; i < cmd.size(); ++i)
    {
        char cmd_c = cmd[i];

        pair<int, int> cmd_p = p_dir[cmd_c - 'A'];

        if (cmd_p.first == 0 && cmd_p.second == 0 && sight[sr][sc] == '#')
        {
            sight[sr][sc] = '.';
            bfs(v, sight, sr, sc);
        }
        else
        {
            sr += cmd_p.first;
            sc += cmd_p.second;

            sr = max(sr, 0);
            sc = max(sc, 0);

            sr = min(sr, r);
            sc = min(sc, c);
        }
    }

    sight[sr][sc] = '.';
    for (int i = 0; i < 4; ++i)
    {
        int ddr = sr + dr[i];
        int ddc = sc + dc[i];

        if (is_range(ddr, ddc))
        {
            sight[ddr][ddc] = '.';
        }
    }

    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            cout << sight[i][j];
        }
        cout << "\n";
    }
}
