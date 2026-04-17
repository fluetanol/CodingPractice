#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }

    int k;
    cin >> k;

    for (int tc = 0; tc < k; ++tc)
    {
        int i, j, x, y;
        cin >> i >> j >> x >> y;

        int sum = dp[x][y] - dp[i - 1][y] - dp[x][j - 1] + dp[i - 1][j - 1];
        cout << sum << "\n";
    }

    return 0;
}
