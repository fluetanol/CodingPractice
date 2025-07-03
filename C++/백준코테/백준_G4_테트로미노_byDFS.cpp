#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxv = -1;
int visit[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isRange(int x, int y, int m, int n)
{
    return (x >= 0 && x < m) && (y >= 0 && y < n);
}

void dfs(int depth, int **&arr, bool **&visited, int x, int y, int sum, int n, int m)
{
    if (depth == 3)
    {
        maxv = max(maxv, sum);
        return;
    }

    visit[depth][0] = x;
    visit[depth][1] = y;
    visited[y][x] = true;
    for (int i = 0; i < 4; i++)
    {
        int ddx = x + dx[i];
        int ddy = y + dy[i];

        if (isRange(ddx, ddy, m, n) && !visited[ddy][ddx])
        {
            dfs(depth + 1, arr, visited, ddx, ddy, sum + arr[ddy][ddx], n, m);
        }
    }
    visited[y][x] = false;
}

// ㅗ ㅜ ㅏ ㅓ
void specialCase(int **&arr, int x, int y, int n, int m)
{
    int count = 0;
    int sum = arr[y][x];

    // 가운데를 기점으로, 4방향을 전부 더함
    for (int i = 0; i < 4; i++)
    {
        int ddx = x + dx[i];
        int ddy = y + dy[i];

        if (isRange(ddx, ddy, m, n))
        {
            sum += arr[ddy][ddx];
            count++;
        }
    }

    // 그냥 불가능
    if (count < 3)
        return;
    // 방향 하나는 들어갈 수 없어서 고정된 형태
    else if (count == 3)
    {
        maxv = max(maxv, sum);
    }

    // 이제 한 방향씩만 빼면 ㅏ, ㅓ , ㅗ, ㅜ 형태가 나옴
    else
    {
        for (int i = 0; i < 4; i++)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            maxv = max(maxv, sum - arr[ddy][ddx]);
        }
    }
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    bool **visited = new bool *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
        visited[i] = new bool[m]{false};
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dfs(0, arr, visited, j, i, arr[i][j], n, m);
            specialCase(arr, j, i, n, m);
        }
    }

    cout << maxv << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}

/*
    풀이법

    놀랍게도 DFS로 푸는 방법이 있었는데, 연속된 위치의 4칸을 방문해야한다 라는 점 때문에
    자연스러운 사방탐색 DFS로 풀 수 있다.

    다만, ㅗ, ㅜ, ㅏ, ㅓ 형태는 DFS로 컨트롤 하기가 까다롭기 때문에 별도의 로직으로 분리했다.
    가운데 위치 X,Y를 기준으로 4방향중 하나만 뺀게 ㅗ, ㅜ, ㅏ, ㅓ 형태이기 때문에
    가운데 위치를 기준으로 4방향을 모두 더한 후, 하나씩 빼면서 최대값을 갱신하는 식으로 구현했다.

    가배쨩이 알려줌 
    역시 똑똑한 사람은 보법이 달라~
*/