#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
    일단 다익스트라로 풀어보겠음
*/
int map[200001];

struct ans
{
    int time;
    int count;
};

ans djk(int n, int k)
{

    queue<int> q;
    q.push(n);

    int time = 0;
    int count = 0;
    bool isFinish = false;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; ++i)
        {
            int new_n = q.front();
            q.pop();

            if (new_n == k)
            {
                isFinish = true;
                count++;
            }

            if (!isFinish)
            {
                int prev_n = new_n - 1;
                int next_n = new_n + 1;
                int jump_n = new_n * 2;

                // 등호가 들어가야 함, 이 문제는 가능한 모든 최단 시간 경로를 찾아야 해서
                // time = t일 때의 모든 경로를 알아야 하기 때문...
                if (prev_n >= 0 && map[prev_n] >= time + 1)
                {
                    q.push(prev_n);
                    map[prev_n] = time + 1;
                }
                if (next_n <= 200000 && map[next_n] >= time + 1)
                {
                    q.push(next_n);
                    map[next_n] = time + 1;
                }
                if (jump_n <= 200000 && map[jump_n] >= time + 1)
                {
                    q.push(jump_n);
                    map[jump_n] = time + 1;
                }
            }
        }
        if (isFinish)
            break;
        time++;
    }

    return {time, count};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    if (n >= k)
        cout << n - k << "\n"
             << 1;
    else
    {
        for (int i = 0; i <= 200000; ++i)
            map[i] = INT_MAX;
        ans ans_djf = djk(n, k);
        cout << ans_djf.time << "\n"
             << ans_djf.count;
    }
}
