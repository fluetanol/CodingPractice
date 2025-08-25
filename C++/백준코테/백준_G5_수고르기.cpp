#include <iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;



int main()
{
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<int> val(n);

    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }
    
    sort(val.begin(), val.end());

    int mindiff = 2000000000;
    int j = 0;
    for (int i = 1; i < n; ++i){
        
        while (val[i] - val[j] >= m && i > j) {
            int diff = val[i] - val[j];
            mindiff = diff >= m ? min(mindiff, diff) : mindiff;
            ++j;
        }

    }

    cout << mindiff;
}




/*
    정렬을 시키면 투 포인터로 풀수 있다.
    정렬의 성능은 nlogn이고
    그냥 완탐은 n^2이기 때문에 
    정렬 후 투 포인터를 갈기는게 훨~씬 빠름을 알수있다...

*/