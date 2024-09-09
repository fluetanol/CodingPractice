// 문제번호 : 11726
// 2xn타일링
// 푼 시간 : 20분
// 알고리즘 분류 : DP

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    vector<int> v(1000);
    v[0] = 1;
    v[1] = 2;

    int n;
    cin >> n;
    for (int i = 2; i < n; i++)
    {
        v[i] = (v[i - 1] + v[i - 2]) % 10007;
    }
    cout << v[n - 1] << endl;
}
/*
    전에 풀었던 1,2,3더하기 문제와 거의 유사한 문제.
*/