// 문제번호 : 1068번
// 트리
// 푼 시간 : 1시간
// 알고리즘 분류 : 트리, DFS

#include <iostream>
#include <vector>

using namespace std;

int leafCount(vector<vector<int>> &adjMatrix, int startNode)
{
    int count = 0;
    if (adjMatrix[startNode].size() == 0)
    {
        return 1;
    }
    else
    {
        int size = adjMatrix[startNode].size();
        for (int i = 0; i < size; i++)
        {
            count += leafCount(adjMatrix, adjMatrix[startNode][i]);
        }
    }
    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<int>> adjMatrix(n);
    int root;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] != -1)
            adjMatrix[v[i]].push_back(i);
        else
            root = i;
    }

    int deleteNode;
    cin >> deleteNode;

    if (v[deleteNode] == -1)
        cout << 0 << endl;
    else
    {
        for (int i = 0; i < adjMatrix[v[deleteNode]].size(); i++)
        {
            if (adjMatrix[v[deleteNode]][i] == deleteNode)
            {
                adjMatrix[v[deleteNode]].erase(adjMatrix[v[deleteNode]].begin() + i);
                break;
            }
        }
        cout << leafCount(adjMatrix, root);
    }
}

/*
    adjustMatrix를 이용한 트리 구조의 리프 노드 개수 구하기 문제
    굳이 삭제동작을 전부 할 필요가 없이
    삭제할 노드의 부모 노드에서 삭제할 노드에 대한 연결 정보를 없애버리고
    그 뒤에 루트 노드부터 트리 순회하며 리프 노드의 갯수를 구하기만 해도 된다.
    이렇게 하면 삭제 동작을 할 때마다 트리를 다시 구성할 필요가 없다.

    시간 복잡도는 결국 리프노드를 구하기 위해 n개의 노드를 전부 순회해봐야하므로
    O(n)이다.

    괜히 삭제동작을 전부 구현하려다가 머리만 더 복잡해질뻔한 문제.


*/