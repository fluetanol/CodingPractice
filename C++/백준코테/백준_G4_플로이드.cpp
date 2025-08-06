#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

long long d[101][101];
/*
    a -> b 를 [a][b]라 할 때
    min ( [a][b], [a][c] + [c][b] );
*/

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == j) d[i][j] = 0;
            else d[i][j] = INT_MAX;
        }
    }

    for (int i = 0; i < m; ++i) {
        long long a, b, v;
        cin >> a >> b >> v;
        d[a][b] = min(d[a][b], v);
    }


    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                  d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            long long  val = d[i][j] >= INT_MAX ? 0 : d[i][j];
            cout << val << " ";
        }
        cout << '\n';
    }
   
}



/*
    그냥 플로이드 워셜로 풀면 되는데 (min(d[a][b] , d[a][k] + d[k][b]))

    input 조건에 a->b로 가는길이 한개가 아니다 라는 이 조건 빼먹어서 대가리 부숴진 문제

    더 나은 a->b로 초기화 시켜주면 된다

    참고로 a->a케이스는 국룰로 0으로 초기화 함
*/