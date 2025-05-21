// 분류 : 기하학, 수학
// 원의 방정식에 대한 이해도만 있으면 풀리는 문제이다.


#include <iostream>
using namespace std;

bool circle(int*& planet, int pos[2]) {
	return (pos[0] - planet[0])*(pos[0] - planet[0]) + (pos[1] - planet[1])*(pos[1] - planet[1])
		< (planet[2] * planet[2]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int TC; 
	cin >> TC;

	for (int t = 1; t <= TC; t++) {
		int start[2], end[2];
		int n;
		cin >> start[0] >> start[1] >> end[0] >> end[1];
		cin >> n;

		int** planet = new int*[n];
		for (int i = 0; i < n; i++) {
			planet[i] = new int[3];
			for (int j = 0; j < 3; j++) {
				cin >> planet[i][j];
			}
		}

		
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (circle(planet[i], start) != circle(planet[i], end)) {
				count++;
			}
		}
		
		cout << count << '\n';


		for (int i = 0; i < n; ++i) delete[] planet[i];
		delete[] planet;
	}


	return 0;
}

