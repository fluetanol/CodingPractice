#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, M;
vector<int> Adj[501]; // 인접 리스트
int Edge[501][501];   // 인접 행렬
int indegree[501];    // 진입차수
int result;           // 출력값

void topology_sort();

int main()
{

    cin >> N >> M;
    int a, b;

    // Adj[a] 인접행렬 a -> b
    // indegree[b] 진입차수 +1
    // Edge[a][b] = Edge[b][a] = 1
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        Adj[a].push_back(b);
        indegree[b] += 1;
        Edge[a][b] = 1;
        Edge[b][a] = 1;
    }

    // 위상정렬
    topology_sort();

    cout << result << '\n';
}

void topology_sort()
{

    int tmp, tmp2, sz;
    deque<int> zero_queue;  // 진입차수가 0인 노드 queue
    deque<int> check_queue; // 지나온 노드 중에서 확인이 필요한 노드 queue

    // zero_queue에 진입차수가 0인 노드 삽입
    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            zero_queue.push_back(i);
        }
    }

    // zero_queue가 빌 때까지 수행
    // 현재 문제에서는 cycle 가능성 없음
    while (!zero_queue.empty())
    {

        tmp = zero_queue.front();
        zero_queue.pop_front();

        // check_queue의 원소들이 현재 노드보다 확실히 작은지 확인
        sz = check_queue.size();
        for (int i = 0; i < sz; i++)
        {
            tmp2 = check_queue.front();
            check_queue.pop_front();

            // check_queue의 원소가 현재 노드와 연결되어 있지 않으면 확실히 작은지 알 수 없음
            if (Edge[tmp][tmp2] == 0)
                check_queue.push_back(tmp2);
        }

        // check_queue와 zero_queue가 비어있다면 현재 노드는 키 순서를 정확히 알 수 있음
        if (check_queue.empty() && zero_queue.empty())
            result++;

        // 현재 노드와 연결된 노드의 인접차수 -1
        for (int i : Adj[tmp])
        {
            if (--indegree[i] == 0)
                zero_queue.push_back(i);
        }

        // check에 현재 노드 삽입
        check_queue.push_back(tmp);
    }
}