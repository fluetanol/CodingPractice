#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//11724 연결 요소의 개수
int bfs(bool*& visited, vector<vector<int>>& v, int n) {
    int count = 0;
    
    for (int i = 1; i <= n; i++) {

        //미방문한 시작 노드
        if (visited[i] == false) {
            count++;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int head = q.front();
                q.pop();

                //head  노드의 모든 근방 정점들 방문
                for (int j = 0; j < v[head].size(); ++j) {
                    int element = v[head][j];

                    //방문 시도하려는 노드들은 일단 true로 바꿈
                    if (visited[element] == false) {
                        visited[element] = true;
                        q.push(element);
                    }
                }
            }
        }


    }

    return count;
}



int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n + 1);
    bool* visited = new bool[n+1] { false };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }


    int count = bfs(visited, v, n);

    cout << count << "\n";
}

