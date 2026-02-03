#include <iostream>
#include  <vector>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int MAX = 100000;
    int INF = 1e9;

    vector<int> dist(MAX + 1, INF);
    deque<int> dq;

    dist[n] = 0;
    dq.push_back(n);

    while (!dq.empty())
    {
        int x = dq.front();
        dq.pop_front();

        if (x == k)
        {
            break;
        }

        if (x * 2 <= MAX && dist[x * 2] > dist[x])
        {
            dist[x * 2] = dist[x];
            dq.push_front(x * 2);
        }
        if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1)
        {
            dist[x - 1] = dist[x] + 1;
            dq.push_back(x - 1);
        }
        if (x + 1 <= MAX && dist[x + 1] > dist[x] + 1)
        {
            dist[x + 1] = dist[x] + 1;
            dq.push_back(x + 1);
        }
    }

    cout << dist[k];
}