// 문제번호 : 11279
// 최대 힙
// 푼 시간 : 5분
// 알고리즘 분류 : 힙

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (val != 0)
        {
            heap.push(val);
        }
        else
        {
            if (heap.size() == 0)
                cout << 0 << "\n";
            else
            {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
    }
}

//최소힙에 이어 연습용으로 풀어본 문제다.
//최대힙은 less<int>를 사용하도록 하자.