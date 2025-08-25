#include <iostream>
#include<cmath>
using namespace std;


int val[100000];


int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    int msum = -999999999;
    int j = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += val[i];

        if (i - j + 1  == k) {
            msum = max(sum, msum);
            sum -= val[j++];
        }   
    }

    cout << msum;

}

