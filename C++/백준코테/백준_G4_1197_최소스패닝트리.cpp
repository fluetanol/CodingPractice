#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
    int n;
    long long w;

    bool operator<(const node n) const
    {
        return w > n.w;
    }
};

long long minSpanningTree(vector<vector<node>> &adj_list, int v)
{
    priority_queue<node> pq;
    vector<bool> visited(v + 1);
    pq.push({1, 0});

    int count = 0;
    long long sum = 0;

    while (!pq.empty())
    {
        if (count == v)
            break; // 초기화 노드 제외하면 사실상 v-1개까지 세는 것

        node new_node = pq.top();
        int new_n = new_node.n;
        long long new_w = new_node.w;
        pq.pop();

        // 현재 간선 weight 을 기준으로 정렬되어있기 때문에
        // 함부로 visited를 미리 체크하면 안됨
        // 온전히 유효 엣지라고 받아들여져야 그 때서야 visited를 체크해야 하는 것이고
        // 그 뒤에 혹시나 이미 선택된 노드를 또 간택하는 일이 있을 수 있으니 이런 이중 체크를 하는것
        if (visited[new_n])
            continue;
        visited[new_n] = true;
        sum += new_w;
        count++;

        for (int i = 0; i < adj_list[new_n].size(); ++i)
        {
            node next_node = adj_list[new_n][i];
            int next_n = next_node.n;
            long long next_w = next_node.w;

            if (visited[next_n])
                continue;
            pq.push(next_node);
        }
    }

    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int v, e;
    cin >> v >> e;

    vector<vector<node>> adj_list(v + 1);

    for (int i = 0; i < e; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    cout << minSpanningTree(adj_list, v);
}
