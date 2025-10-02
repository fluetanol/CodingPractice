

#include <iostream>
#include <vector>
#include<algorithm>
#include<sstream>
using namespace std;



int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;


    vector<vector<int>> v(n + 1);
    for (int i = 0; i <= n; ++i) {
        v[i].resize(n+1);
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> sumv(n + 1);
    for (int i = 0; i <= n; ++i) {
        sumv[i].resize(n + 1);
    }

    //누적합 초기화
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            //새로더할 값 + 이전 행 + 이전 열 - 겹친 이전 행과 열
            sumv[i][j] = v[i][j] + sumv[i][j - 1] + sumv[i - 1][j] - sumv[i - 1][j - 1];
        }
    }


    for (int i = 0; i < m; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        

        // x1 < x2 , y1 < y2이다
        // 누적합 초기화 과정의 반대라 생각하고 식 세우면 된다.
        // 가장 큰 영역(x2, y2) - (그 바깥의 영역들) + 쓸데 없이 중복으로 뺀 바깥 영역
        int sum =  sumv[x2][y2] - sumv[x2][y1-1] - sumv[x1-1][y2] + sumv[x1-1][y1-1];

        cout << sum << endl;
    }
}


