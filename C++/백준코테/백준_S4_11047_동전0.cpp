//알고리즘 : 그리디
//동전이 배수관계라 대체 가능한 관계라서 그리디 하게 풀어도 되는 문제
//배수관계가 아니라면 브루트포스나 DP

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    
    for (int i = 0; i < n; ++i) {
        int val = 0;
        cin >> val;
        if (val > k) {
            n = i;
            break;
        }
        v[i] = val;
    }

    //동전이 서로가 대체 가능한 관계임
    int count = 0;
    for (int i = n-1; i >= 0; --i) {
        if (k >= v[i]) {
            count += k / v[i];
            k = k % v[i];
        }
    }

    cout << count;


}

