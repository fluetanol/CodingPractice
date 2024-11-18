// 문제번호 : 1915번
// 가장 큰 정사각형
// 푼 시간 : 1시간 반
// 알고리즘 분류 : DP

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

	vector<vector<int>> v(n);
	vector<vector<int>> check(n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		v[i].resize(m);
		check[i].resize(m);
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			v[i][j] = s[j] - '0';
			if (v[i][j] == 1) max = 1;
			if (i == 0 || j == 0) {
				check[i][j] = v[i][j];
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (check[i - 1][j - 1] == 0 || check[i - 1][j] == 0 || check[i][j - 1] == 0 || v[i][j] == 0) {
				check[i][j] = v[i][j];
			}
			else {		
				check[i][j] = min(check[i-1][j-1] , min(check[i - 1][j], check[i][j - 1])) + 1;
			}

			if (max < check[i][j]) max = check[i][j];
		}
	}

	cout << max * max << endl;
}
