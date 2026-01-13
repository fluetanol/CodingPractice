#include <iostream>
#include <queue>
using namespace std;

/*
        3
       34
      34_
      4_5
      _5_
      5__
      ___


        3
       3
      3 4
       45
      45
      5
      ___

      이건 그리디 하게 풀면 풀릴 것이다.
      근거를 들어보면

      1. 만약 a, b, c가 있다고 해보자. a와 c가 같이 올라갈 수 있는 환경이라면, 그게 훨씬 더 빠를테니 그렇게 하는게 낫다
      2. 만약 하중 상 a, b까지만 있을 수 있다면, a가 반드시 다 지나가야 c가 올라탈 수 있다. 즉, 이건 b의 문제가 아님

      이에 의해, 만약 다리길이가 k라고 하면, a와 c는 반드시 k의 오프셋이 생길 수 밖에 없고, a가 k의 시간을 소모하여 다 지나가야만
      c가 올라탈 수 있다는 걸 의미한다. 그리고 c가 다 지나가는 시간 또한 k이므로 k의 시간이 추가로 소모하게 된다.

      따라서 중간에 껴있는 b가 어떻게 올라타든 간에 a와 c가 전부 건너는 시간은 2k가 반드시 소모된다.

      따라서 그냥 가능한 한 당장 최대한으로 건널 수 있는 그리디한 선택을 계속 하는 게 낫다.

*/

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }

    int second = 0;
    int w_sum = 0;
    int idx = 0;

    queue<int> q;
    while (idx < n)
    {
        int w_truck = v[idx];

        if (q.size() == w)
        {
            w_sum -= q.front();
            q.pop();
        }

        // 다리 위에 올라탈 수 있다면 큐에 넣고 전체 중량 측정
        if (w_sum + w_truck <= l)
        {
            q.push(w_truck);
            w_sum += w_truck;
            idx++;
        }
        else
        {
            q.push(0);
        }

        second++;
    }

    second += w;

    cout << second;
}
