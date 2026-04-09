#include <iostream>
#include <cmath>

using namespace std;

int adj[16][16];
int dp[16][1 << 16];
int n;
int maxval = 999999999;

// 출발점은 0으로 가정함
int TSP(int cur, int visited)
{

    if (visited == (1 << n) - 1)
    {
        return adj[cur][0] > 0 ? adj[cur][0] : maxval;
    }
    if (dp[cur][visited] != -1)
    {
        return dp[cur][visited];
    }

    // 방문은 했으니 maxval로 초기화함, -1은 어디까지나 미방문 상태를 표시하는 용도
    dp[cur][visited] = maxval;

    for (int next = 1; next < n; ++next)
    {

        // cur->next 이동이 가능하며, next로 방문한 적이 없는 경우
        if (adj[cur][next] > 0 && !(visited & (1 << next)))
        {
            dp[cur][visited] = min(
                dp[cur][visited],
                adj[cur][next] + TSP(next, visited | (1 << next)));
        }
    }

    return dp[cur][visited];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (1 << n); ++j)
        {
            dp[i][j] = -1;
        }
    }

    int ans = TSP(0, 1);
    cout << ans << "\n";

    return 0;
}
