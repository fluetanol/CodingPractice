#include <iostream>
#include <vector>


using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    // reach[i][j] = i가 j보다 작다(= i -> j 로 도달 가능)
    vector<vector<bool>> reach(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        reach[a][b] = true;
    }

    // Floyd-Warshall: 전이 관계 채우기 (transitive closure)
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            if (!reach[i][k])
                continue; // 가지치기
            for (int j = 1; j <= N; j++)
            {
                if (reach[k][j])
                    reach[i][j] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        int bigger = 0, smaller = 0;

        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            if (reach[i][j])
                bigger++; // i < j
            if (reach[j][i])
                smaller++; // j < i
        }

        if (bigger + smaller == N - 1)
            ans++;
    }

    cout << ans << "\n";
    return 0;
}
