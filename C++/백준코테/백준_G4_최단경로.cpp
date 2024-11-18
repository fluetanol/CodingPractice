// 문제번호 : 1753번
// 최단경로
// 푼 시간 : 시간초과...
// 알고리즘 분류 : 그리디, 다익스트라

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct path
{
    int v;
    int w;
};

struct compare
{
    bool operator()(path a, path b)
    {
        return a.w > b.w;
    }
};

void BFS(vector<vector<path>> &tree, priority_queue<path, vector<path>, compare> &q, vector<int> &shortest)
{
    while (!q.empty())
    {
        path p = q.top();
        q.pop();

        for (int i = 0; i < tree[p.v].size(); i++)
        {
            path newp = tree[p.v][i];

            // 기존의 값보다 새로 들어오는 루트 중 더 작은 걸 저장
            if (shortest[newp.v] > shortest[p.v] + newp.w)
            {
                shortest[newp.v] = shortest[p.v] + newp.w;
                q.push({newp.v, shortest[newp.v]});
                //!!!!!!!!! 주의, 새로 들어가게 되는 큐에는 갱신된 거리를 넣어서 판단하게 한다.
                // 그게 맞는 게, 만약 해당 노드를 거쳐 가는게 더 최단거리가 맞다면, 갱신된 거리를 거쳐서도 최단 거리가 될 것이기 때문
                // 다만, 다익스트라의 본질은 그리디이므로, 갱신된 거리보다 더 짧은 노드를 거칠때의 상황부터 확인해보고,
                //  그 다음 그러고서도 후순위로 갱신된 거리의 노드가 더 짧다면 그걸 고르면 그만인것이다.
                // 지금까지는 원래의 노드 w를 그대로 넣어버려서 계속 최단거리 갱신 확인이 안된터라 특정 테케에서
                // 무한루프에 빠지거나, 큐에 필요 이상의 데이터가 자꾸 들어가는 문제가 있었나봄
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int V, E, N;
    cin >> V >> E >> N;

    vector<vector<path>> tree(V + 1);
    vector<int> shortest(V + 1, INT_MAX);
    shortest[N] = 0;
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
    }

    priority_queue<path, vector<path>, compare> q;
    q.push({N, 0});

    BFS(tree, q, shortest);

    for (int i = 1; i < shortest.size(); i++)
    {
        if (shortest[i] == INT_MAX)
            cout << "INF" << "\n";
        else
            cout << shortest[i] << "\n";
    }
}

/*
    다익스트라의 동작원리를 정리해보자.

    1. 시작점을 일단 큐에 넣는다.
    
    2. 시작점과 가장 가까운 노드들과의 weight를 비교해서 표에 갱신한다.
    
    3. "갱신된 노드들을" 큐에 넣는다. 제발 갱신된 노드들을 넣어라.
    
    4. 이후 큐에서 노드를 하나씩 빼서, 현재의 shortestpath와 비교하여
    이전에 탐색한 노드의 최단 거리 + 현재 방문할 노드의 최단거리와
    이미 기록된 shortestpath의 거리를 비교하며 최솟값을 계속 갱신한다.
    
    5. 만약 유지가 되는게 아니라 갱신이 이루어졌다면, 해당 방문 노드의 주변 노드를
    재탐색하여 갱신 할 여지가 생기므로, 갱신된 데이터를 다시 큐에 넣어서 재탐색 또한 유도한다.
    
    6. 이를 반복하면, 결국 더 이상 재 방문할 여지가 없어지는 순간이 오는데 그때 자연스럽게 종료하면 된다.



    갱신된 노드들을 넣으라는 건 성능을 위해 특히 우선순위 큐를 쓰는 경우 때문에 그런건데,
    우선순위 큐에는 반드시 가장 weight가 짧은 노드부터 탐색하도록 되어있다.
    왜냐하면 그렇게 해야 그리디하게 가장 짧은 노드부터 탐색하면서 최단거리를 찾아나갈 수 있기 때문이다.

    아래 예시를 보자.

    ex) 만약 시작점이 1번노드고
     1 : {2, 5} (1번 노드에서 2번노드로 가는 가중치 5) 이라면
    1번 노드에서 2번 노드로 가는 가중치는 3이다.
    큐에는 여전히 {2, 5}을 넣어도 된다.
    ...
    그런데 만약 어찌저찌 흘러가다가, 4 :{2, 1}이라는 정보가 들어오고,
    또, 지금까지 발견된 4의 최단거리가 2라고 기록되었다는 걸 보게 된다면
    시작노드로 부터 어떻게든 4번 노드를 거쳐서 2번 노드로 가는 거리는 2 + 1 = 3이다.
    이미 2에 기록된 거리 5보다 더 짧으므로, 2번 노드의 최단거리를 3으로 갱신해야 한다.

    즉, 시작 노드로부터 2번 노드로 갈 수 있는 최단 거리가 앞으로는 4번 노드를 거쳐가는 3이라는 것이고,
    2번 노드와 연결되어 있는 모든 노드들이 이 거리 3에 맞춰서 재 갱신될 여지가 생긴다.

    그런데 2번 노드를 재 탐색 했다는 사실을 알고, 재 방문하여 재 갱신해야 한다는 사실은 알면서,
    여전히 기존의 {2, 5}를 큐에 넣어버린다면 2번이 갱신된 사실을 모르게 되므로 위의 갱신 관련 조건문

    if( shortest[newp.v] > shortest[p.v] + newp.w)
            {
                shortest[newp.v] = shortest[p.v] + newp.w;
                q.push({newp.v, shortest[newp.v]});
            }

    이 오작동을 하게 되며,

    우선순위 큐에서 가중치가 3으로 변한걸 알고 우선 순위 큐를 다시 재정렬 해줘야 하는데
    잘못된 정렬이 이루어지면서 top()에 와야 할 데이터도 잘못된 순서의 데이터가 나오는 바,
    계속 꼬이면서 무한루프 또는 불필요한 데이터가 큐에 쌓이면서 시간초과하는 문제가 발생한다.
    
    아무튼 다익스트라의 핵심은 
    "현재 상황에서 가장 짧게 갈 수 있는 노드들을 거쳐서, 다음 노드들을 최단 거리로 갈 수 있는 방법을 계속 갱신하는 것"
    이라는 점을 염두해두자.
*/