#include <iostream>
#include <queue>
#include <climits>

using namespace std;

/*
    1초 후에 X-1 또는 X+1
    아무 대가 없이 2*X

    1. 0일 땐 2*X를 쓰면 안됨
    2. 어떤 지점에 도달하면 그 지점에 대한 초를 적어줌
    3. 만약 초가 더 낮게 갱신이 가능하다면 갱신하고 다시 X-1, X+1, 2*X에 대한 연산을 해줌
    4. 만약 같거나 더 크다면 그 루트는 버림

    - 이 문제의 기막힌 특징
    어떤 지점에 최소 시간으로 도달한 경우, 그 지점의 모든 제곱수들은 동일한 시간이 걸림
     -> 이걸 이용해서 많은 가지치기가 가능

    순간 이동을 먼저 해야 최소 루트를 더 빠르게 찾을 확률이 높음
    -> 순간 이동은 시간 소모가 전혀 없기 때문임



     - 사용 자료구조
     1. 100000개 크기의 배열
     2. 큐
*/

// 위치, 해당 위치까지의 시간
struct info
{
    int pos = 0;
    int time = 0;

    // true면 해당 객체가 더 아래로 간다. time이 낮을 수록 위로 간다. pos가 낮을 수록 위로 간다.
    bool operator<(const info &info) const
    {
        if (time != info.time)
            return time > info.time;
        else
            return pos > info.pos;
    }
};

// 시작점, 도착점
int BFS(int n, int k, vector<int> v)
{
    priority_queue<info> q;
    q.push({n, 0});
    int ans = 0;

    while (!q.empty())
    {
        info out = q.top();
        q.pop();
        int pos = out.pos;
        int time = out.time;

        // cout << pos << " " << time << endl;
        if (pos == k)
            return time;
        if (v[pos] == INT_MAX)
            v[pos] = time;

        if (pos != 0)
        {
            int temp_pos = pos;

            // 배수로 갈 수 있는 모든 케이스
            while (true)
            {
                // cout << temp_pos << endl;
                temp_pos *= 2;
                // 범위를 벗어났거나 이미 값이 채워진 상태
                if (temp_pos >= v.size() || v[temp_pos] != INT_MAX)
                    break;
                v[temp_pos] = time;
                q.push({temp_pos, time});
            }
        }

        // 앞으로 간 케이스
        if (pos + 1 < v.size() && v[pos + 1] == INT_MAX)
            q.push({pos + 1, time + 1});
        // 뒤로 간 케이스
        if (pos - 1 >= 0 && v[pos - 1] == INT_MAX)
            q.push({pos - 1, time + 1});
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> v(k + 2, INT_MAX);

    // 뒤로 가는 방법이 후진 한칸 말곤 없어서 그럼
    if (n >= k)
    {
        cout << n - k;
    }
    else
    {
        cout << BFS(n, k, v);
    }
}
