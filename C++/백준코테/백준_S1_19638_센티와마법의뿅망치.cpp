#include <iostream>
#include <queue>
using namespace std;

/*
    곰곰히 생각해보니, 힙트리 쓰는게 맞아보이지 않나 싶기도 하고
    그래서 최댓값을 찾는 건 힙트리에서 금방 찾아버리는 거고
    그리고 맨 마지막에 보이는 최댓값이 센티의 키보다 작다면,
    당연히 전체는 다 작다고 볼 수 밖에 없다는 거지 ㅇㅇ
*/

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<int, vector<int>> pq;

    int n, h, t;
    cin >> n >> h >> t;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        pq.push(k);
    }

    bool flag = true;
    for (int i = 0; i <= t; ++i)
    {
        int top = pq.top();

        // 이렇게 선 점검 후 연산을 한 이유는
        // 안 때려도 되는 케이스를 걸러내기 위해서 그렇습니다
        if (top < h)
        {
            cout << "YES\n"
                 << i;
            flag = false;
            break;
        }
        else if (top == 1 || i == t)
        {
            break;
        }

        top = top / 2;
        pq.pop();
        pq.push(top);
    }

    if (flag)
    {
        cout << "NO\n"
             << pq.top();
    }
}
