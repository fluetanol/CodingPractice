#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &lis_cache, int val)
{
    int left = 0;
    int right = lis_cache.size();

    while (left < right)
    {
        int mid = (left + right) / 2;

        if (lis_cache[mid] < val)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    lis_cache[left] = val;

    return left;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    vector<int> lis_cache;
    vector<int> lis;
    lis_cache.push_back(0);

    for (int i = 0; i < n; ++i)
    {
        if (lis_cache.back() < v[i])
        {
            lis_cache.push_back(v[i]);
            lis.push_back(lis_cache.size() - 1);
        }
        else
        {
            int idx = binary_search(lis_cache, v[i]);
            lis.push_back(idx);
        }
    }

    int val = 99999;
    int expect_lis_val = lis_cache.size() - 1;
    vector<int> lis_sort(expect_lis_val);
    for (int i = n - 1; i >= 0; --i)
    {
        if (lis[i] == expect_lis_val && val > v[i])
        {
            val = v[i];
            lis_sort[--expect_lis_val] = v[i];
        }
    }

    cout << lis_sort.size() << "\n";
    for (int i = 0; i < lis_sort.size(); ++i)
    {
        cout << lis_sort[i] << " ";
    }
    cout << "\n";

    return 0;
}
