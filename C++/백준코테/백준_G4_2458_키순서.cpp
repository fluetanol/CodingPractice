#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    자기보다 작은 녀석의 수 a
    자기보다 큰 녀석의 수 b

    전체 노드 수가 n개라면 자신을 제외하여
    a + b = n-1이 될 수 있다면 자신의 키를 명확히 알 수 있는 것이다.

    내 아이디어는 이렇다

    1. 순방향 그래프와 역방향 그래프를 따로 만들어둔다
    2. 한 노드 k에 대해
    - 순방향 그래프에서 자기보다 큰 녀석을 찾는다. 큰 녀석의 갯수를 a라 함
    - 역방향 그래프에서 자기보다 작은 녀석을 찾는다. 작은 녀석의 갯수를 b라 함
    3. 이렇게 찾은 a + b = n-1이 되는 지 확인한다. 되면 count를 1 올림
    4. k = n-1이 될때까지 반복하여 count를 출력한다.

    어우 쉬워
    사용할 그래프 탐색 로직은 bfs면 충분할 듯 하다.


    참고 : 문제 특성상 키를 주제로 하여 대소 비교를 그래프로 표시한 상황이니
    순환그래프가 나올 일은 없을 것이다. 키 대소비교에 순환 그래프는.... 무엇을 의미하는 것이지?

*/

int bfs(int node, vector<vector<int>> &tree)
{
    queue<int> q;
    vector<bool> visited(tree.size() + 1);

    q.push(node);
    visited[node] = true;

    int ans = -1;
    while (!q.empty())
    {
        int new_node = q.front();
        q.pop();
        ans++;

        for (int i = 0; i < tree[new_node].size(); ++i)
        {
            int next_node = tree[new_node][i];
            if (visited[next_node])
                continue;

            q.push(next_node);
            visited[next_node] = true;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> tree(n + 1);
    vector<vector<int>> rev_tree(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int s, e;
        cin >> s >> e;
        tree[s].push_back(e);
        rev_tree[e].push_back(s);
    }

    int count = 0;
    for (int i = 1; i <= n; ++i)
    {
        int ans = bfs(i, tree) + bfs(i, rev_tree);
        if (ans == n - 1)
            count++;
    }

    cout << count;
}
