// 문제번호 : 11725번
// 트리의 부모 찾기
// 푼 시간 : 30분
// 알고리즘 분류 : 그래프 탐색, DFS

#include<iostream>
#include <vector>
#include <algorithm>
    using namespace std;

void DFS(vector<int> &visited, vector<vector<int>> &v, int idx)
{
    for (int i = 0; i < v[idx].size(); i++)
    {
        int num = v[idx][i];
        if (visited[num] == 0 && num != 1)
        {
            visited[num] = idx;
            DFS(visited, v, num);
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> v(n + 1);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;

        v[a].push_back(b);
        v[b].push_back(a);
    }
    vector<int> visited(n + 1);
    DFS(visited, v, 1);

    for (int i = 2; i < visited.size(); i++)
    {
        cout << visited[i] << '\n';
    }
}

/*
    endl 시간초과 나니까 쓰지마라...


    ** 참고로 여기에서 disjoint set을 써볼 수 있을까 싶었는데
    disjoint set은 자신의 부모가 아니라, 자신이 속한 트리의 루트 노드를 찾는게
    주 목적이라, 해당 문제에 쓰는 건 부적합하다고 했다.
*/