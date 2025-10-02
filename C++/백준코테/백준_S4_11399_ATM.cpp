// 백준 11399 ATM
// 그리디 알고리즘

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    

    int sum = v[0];
    vector<int> subsum(n);
    subsum[0] = v[0];
    for (int i = 1; i < n; ++i) {
        subsum[i] = subsum[i - 1] + v[i];
        sum += subsum[i];
    }
   
    cout << sum;
    
}

