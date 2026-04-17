#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<int> lis(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        v[i] = k;
    }

    int max_val = -1;
    for (int i = 0; i < n; ++i)
    {
        lis[i] = 1;

        for (int j = i - 1; j >= 0; --j)
        {
            if (v[i] > v[j])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }

        max_val = max(lis[i], max_val);
    }

    cout << max_val << endl;

    return 0;
}
