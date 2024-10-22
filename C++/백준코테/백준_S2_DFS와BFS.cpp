#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 인접 행렬로 푸는 방법
void DFS(vector<vector<bool>> &v, vector<bool> &isVisit, int depth, int size)
{
    isVisit[depth] = true;
    cout << depth + 1 << " ";
    for (int i = 0; i < size; i++)
    {
        if (v[depth][i] == 1 && isVisit[i] != 1)
        {
            DFS(v, isVisit, i, size);
        }
    }
    return;
}

void BFS(vector<vector<bool>> &v, vector<bool> &isVisit, int start, int size)
{
    vector<int> q({start});

    while (q.size() > 0)
    {
        int idx = q.front();
        if (isVisit[idx] != 1)
            cout << idx + 1 << " ";
        isVisit[idx] = 1;

        for (int i = 0; i < size; i++)
        {
            if (v[idx][i] != 0 && isVisit[i] == 0)
            {
                q.push_back(i);
            }
        }
        q.erase(q.begin());
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<bool>> vec(n);
    vector<bool> isVisit(n);
    for (int i = 0; i < n; i++)
    {
        vec[i].resize(n);
    }

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vec[n1 - 1][n1 - 1] = 1;
        vec[n1 - 1][n2 - 1] = 1;
        vec[n2 - 1][n1 - 1] = 1;
    }

    DFS(vec, isVisit, v - 1, n);
    isVisit.clear();
    isVisit.resize(n);
    cout << "\n";
    BFS(vec, isVisit, v - 1, n);
}



// 인접 리스트로 푸는 방법

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(vector<vector<int>> &v, vector<bool> &isVisit, int depth)
{
    if (!isVisit[depth])
    {
        cout << depth + 1 << " ";
        isVisit[depth] = 1;
    }
    for (auto i : v[depth])
    {
        if (!isVisit[i])
        {
            DFS(v, isVisit, i);
        }
    }
}

void BFS(vector<vector<int>> &v, vector<bool> &isVisit, int start)
{
    vector<int> q({start});

    while (q.size() > 0)
    {
        int val = q.front();

        if (!isVisit[val])
        {
            cout << val + 1 << " ";
            isVisit[val] = 1;
        }

        for (int i = 0; i < v[val].size(); i++)
        {
            if (!isVisit[v[val][i]])
            {
                q.push_back(v[val][i]);
            }
        }
        q.erase(q.begin());
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, v;
    cin >> n >> m >> v;

    vector<vector<int>> vec(n);
    vector<bool> isVisit(n);

    for (int i = 0; i < m; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        vec[n1 - 1].push_back(n2 - 1);
        vec[n2 - 1].push_back(n1 - 1);
    }

    for (int i = 0; i < n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }

    DFS(vec, isVisit, v - 1);
    isVisit.clear();
    isVisit.resize(n);
    cout << "\n";
    BFS(vec, isVisit, v - 1);
}


/*
    인접 리스트의 단점은 노드와 노드간의 연결 관계를 알아내는 게 힘들다는 건데
    이 문제는 그런 정보는 필요 없기 때문에 사실 인접 행렬보다 더 좋은 성능을 보인다.

    (아 그리고 sort작업은 전체 데이터 량이 그리 많지 않아서 크게 문제가 되지 않는다.)
*/