// 문제번호 : 1744번
// 수 묶기
// 푼 시간 : 20분
// 알고리즘 분류 : 그리디, 많은 분기

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int a = 0;
    int sum = 0;
    queue<int> q;

    // 음수인 경우
    while (true)
    {
        // 양수인 경우, 남은 걸 비우고 탈출
        if (a == v.size() || v[a] > 0)
        {
            if (!q.empty())
            {
                sum += q.front();
                q.pop();
            }
            break;
        }
        // 이미 음수가 있고, 그 다음 수 또한 음수또는 0이라면 둘을 곱해서 양수화 시킴
        else if (q.size() == 1 && v[a] <= 0)
        {
            sum += q.front() * v[a];
            q.pop();
        }
        // 음수인 경우 push
        else if (v[a] < 0)
        {
            q.push(v[a]);
        }
        a++;
    }

    a = v.size() - 1;
    // 양수인 경우
    while (true)
    {
        if (a < 0 || v[a] < 1)
        {
            if (!q.empty())
            {
                sum += q.front();
                q.pop();
            }
            break;
        }
        else if (v[a] == 1)
        {
            sum += v[a];
        }
        if (q.size() == 1 && v[a] > 1)
        {
            sum += q.front() * v[a];
            q.pop();
        }
        else if (v[a] > 1)
        {
            q.push(v[a]);
        }
        a--;
    }

    cout << sum;
}

/*
    조금 애드훅 같은 그리디 문제인데, 규칙만 잘 파악해서 분기식만 잘 세우면 풀리는 문제다.

    이 문제에서 그리디하게 이득을 볼 수 있는 방법은 다음 세 가지를 신경쓰면 된다.

    1. 음수인 경우, 두 음수를 최대한 묶어서 양수화 시킨다. (0도 포함하여 음수를 제거)
    ->물론 음수 또한 절댓값이 큰 음수 순서대로 묶어주는게 좋다.
    2. 1은 어떻게 곱하든 곱보다 더하기가 더 큰 수여서 묶지 않는다.
    3. 양수는 최대한 큰 두 수 끼리 묶으면 된다.

    위 세 조건에 맞게만 잘 반복문 구현해주면 O(n)에 풀 수 있다.


*/