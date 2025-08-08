#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long arr[2001];


/*
 음수 가능함

 0 1 2 3 
 
 -5 0 5
 
 0 1 2 3 3 ->
*/

bool twopointer(int l, int r, long long val, int validx) {

    bool iscorrect = false;

    while (l < r) {
        long long sum = arr[l] + arr[r];

        if (sum < val) ++l;
        else if (sum > val) --r;
        else if (sum == val && r == validx) {
            --r;
        }
        else if (sum == val && l == validx) {
            ++l;
        }
        else {
            iscorrect = true;
            break;
        }

    }
    return iscorrect;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    long long n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    sort(arr, arr + n);

    int goodCount = 0;
    for (int i = 0; i < n; ++i) {
        goodCount += twopointer(0, n - 1, arr[i], i) ? 1 : 0;
    }

    cout << goodCount << "\n";
}


/*
    투포인터로 풀어도 되고, 범위가 2000이라 2중for문으로도 충분하기 때문에 
    hashmap을 이용하여 풀어봐도 된다.
*/