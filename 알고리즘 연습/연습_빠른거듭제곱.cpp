#include <iostream>
using namespace std;

double fastExp(double a, int b) {
	double ans = 1;
	double multiple = a;
	int exp = abs(b);

	while (exp > 0) {
		if (exp & 1) {
			ans *= multiple;
		}
		exp >>= 1;
		multiple = multiple * multiple;
	}

	if (b < 0) ans = 1 / ans;

	return ans;
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	double a;
	int b;
	cin >> a >> b;

	cout << fastExp(a, b) << endl;

	return 0;
}

