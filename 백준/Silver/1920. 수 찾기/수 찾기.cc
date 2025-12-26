#include <iostream>
#include <unordered_set>
using namespace std;


int main()
{
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;
    unordered_set<int> us;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        us.insert(k);
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        if (us.find(k) != us.end()) {
            cout << 1 << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }


}

