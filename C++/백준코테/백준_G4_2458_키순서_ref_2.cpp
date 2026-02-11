#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <vector>
#include <cstring>
#include <utility>

using namespace std;

vector<int> key[510];
int keychai[510][2]; // 1큰놈 0작은놈
int ans = 0;
bool visit[510] = {
    false,
};

void keyjegi(int stu, int num)
{
    visit[num] = true;
    keychai[num][1]++;
    for (int higher : key[num])
    {
        if (visit[higher])
            continue;
        keychai[stu][0]++;
        keyjegi(stu, higher);
    }
}

int main()
{
    int n, m;
    int a, b;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        key[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        keyjegi(i, i);
        memset(visit, 0, 510 * sizeof(bool));
    }
    for (int i = 1; i <= n; i++)
    {
        if (keychai[i][0] + keychai[i][1] == n)
            ans++;
    }
    printf("%d", ans);
    return 0;
}
