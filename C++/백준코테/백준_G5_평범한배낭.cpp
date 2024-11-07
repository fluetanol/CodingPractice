// 문제번호 : 12865번
// 평범한 배낭
// 푼 시간 : 1시간
// 알고리즘 분류 : (아직 모름)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<vector<int>> &vec, int n, int k, int sum1, int sum2, int &max, int idx)
{
    for (int i = idx; i < n; i++)
    {
        int w = vec[i][0];
        int v = vec[i][1];
        if (sum1 + w <= k)
        {
            if (max < (sum2 + v))
                max = sum2 + v;
            dfs(vec, n, k, sum1 + w, sum2 + v, max, i + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        vec[i].resize(2);

        vec[i][0] = w;
        vec[i][1] = v;
    }

    int max = -1;
    dfs(vec, n, k, 0, 0, max, 0);
    cout << max << endl;
}


/*
    일반적인 dfs 풀이법
    그런데 n이 100까지 주어지기 때문에 시간초과로 권장되지 않는다.
    메모이제이션을 하거나 DP로 풀 만한 요소를 찾아보자.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        vec[i].resize(2);
        vec[i][0] = w;
        vec[i][1] = v;
    }

    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(k + 1);
    }

    for (int i = 0; i < n; i++)
    {
        int weight = vec[i][0];
        int value = vec[i][1];

        for (int j = 0; j < k + 1; j++)
        {
            if (j < weight)
                ans[i][j] = i > 0 ? ans[i - 1][j] : 0;
            else
            {
                ans[i][j] = i > 0 ? max(ans[i - 1][j], value + ans[i - 1][j - weight]) : value;
            }
        }
    }

    cout << ans[n - 1][k] << endl;
}

/*
    풀이가 너무 복잡하므로 노션에 남김
    참고로 시간복잡도는 O(nk)


*/


//아래는 며칠 뒤 스스로 복습용으로 풀어본 코드
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        p[i] = make_pair(w, v);
    }

    vector<vector<int>> dp(k + 1);
    for (int i = 0; i <= k; i++)
    {
        dp[i].resize(n + 1);
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w = p[j - 1].first;
            int v = p[j - 1].second;
            
            if (w > i)
            {
                dp[i][j] = dp[i][j - 1];
            }
            else if (w == i)
            {
                dp[i][j] = max(v, dp[i][j - 1]);
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], v + dp[i - w][j - 1]);
            }
        }
    }

    cout << dp[k][n] << endl;
}
/*
    벡터가 공간 할당에 좀 구리긴 한데 아무튼 통과함

*/