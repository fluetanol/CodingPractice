#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int *cost;

// 첫줄엔 root정보
// 두번째 줄엔 최솟값 정보가 포함됩니다.
int **dj = new int *[2];

int find_parent(int v)
{
    if (v == dj[0][v])
    {
        return dj[0][v];
    }
    return dj[0][v] = find_parent(dj[0][v]);
}

int find_mincost(int v)
{
    if (v == dj[0][v])
    {
        return dj[1][v];
    }
    return find_mincost(dj[0][v]);
}

int cost_update(int v, int cost)
{
    cost = min(dj[1][v], cost);

    if (v == dj[0][v])
    {
        dj[1][v] = cost;
        return dj[1][v];
    }
    return dj[1][v] = cost_update(dj[0][v], cost);
}

void union_node(int a, int b)
{
    a = find_parent(a);
    b = find_parent(b);

    if (a < b)
        dj[0][b] = a;
    else
        dj[0][a] = b;
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m, k;

    cin >> n >> m >> k;

    cost = new int[n + 1];

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    for (int i = 0; i < 2; i++)
    {
        dj[i] = new int[n + 1];
    }
    for (int j = 1; j <= n; j++)
    {
        dj[0][j] = j;
        dj[1][j] = cost[j];
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        union_node(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        cost_update(i, cost[i]);
    }

    bool *v = new bool[n + 1]{false};
    int need = 0;
    for (int i = 1; i <= n; i++)
    {
        int root = find_parent(i);
        if (v[root])
            continue;

        v[root] = true;
        int mincost = find_mincost(i);
        need += mincost;
    }

    if (need > k)
        cout << "Oh no\n";
    else
        cout << need << "\n";

    delete[] cost;
    delete[] v;
    for (int i = 0; i < 2; i++)
        delete[] dj[i];
    delete[] dj;
}


/*
    disjoint set의 응용 문제고
    
    각 집단에 대한 최소 비용을 구하는 건 disjoint set을 전부 구하고 난 뒤에 갱신시켜도 늦지 않는다.
    어차피 disjoint set의 최적화 기법까지 더해버리면 find연산은 O(1)에 가까움

*/