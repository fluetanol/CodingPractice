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
        // 순간이동
        if (x * 2 <= MAX && dist[x * 2] > dist[x])
        {
            dist[x * 2] = dist[x];
            dq.push_front(x * 2);
        }
        // 뒤로
        if (x - 1 >= 0 && dist[x - 1] > dist[x] + 1)
        {
            dist[x - 1] = dist[x] + 1;
            dq.push_back(x - 1);
        }
        // 앞으로
        if (x + 1 <= MAX && dist[x + 1] > dist[x] + 1)
        {
            dist[x + 1] = dist[x] + 1;
            dq.push_back(x + 1);
        }

        //이렇게 해도 어차피 상관 없는게
        //2배로 늘어나는 게 항상 더 빠르기 때문에 앞에 넣어두고
        //1칸씩 가는 건 항상 더 느리기 때문에 뒤에 넣어두어 pq처럼 동작하게 되는 것이다.
        //pq는 logn의 시간복잡도가 있는데, 이건 그렇지 않으니 속도가 더 빠른것
    }

    cout << dist[k];
}