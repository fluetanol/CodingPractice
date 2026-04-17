#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void find_start(vector<int> &inner, queue<int> &q)
{
    for (int i = 1; i < inner.size(); ++i)
    {
        if (inner[i] == 0)
        {
            q.push(i);
        }
    }
}

void topology_sort(vector<vector<int>> &v, vector<int> &inner, vector<int> &outer)
{
    queue<int> q;
    find_start(inner, q);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int i = 0; i < v[node].size(); ++i)
        {

            int next = v[node][i];

            inner[next] = inner[next] > 0 ? inner[next] - 1 : inner[next];

            if (inner[next] == 0)
            {
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1);
    vector<int> inner(n + 1);
    vector<int> outer(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int a, b;

        cin >> a >> b;

        v[a].push_back(b);
        inner[b]++;
        outer[a]++;
    }

    topology_sort(v, inner, outer);

    return 0;
}
