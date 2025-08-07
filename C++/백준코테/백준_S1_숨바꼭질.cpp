//1697
/*
    첫번쨰 시도 : 무식한 BFS 
    메모리 초과로 실패
    큐에 범위 제한없이 막 들어가니 당연히 실패

    두번쨰 시도 : set을 이용한 BFS
    메모리 초과로 인한 실패
    set 자체도 무거운 자료구조고
    가지치기를 했어도 숫자 범위 제한이 없어서 역부족이였다.

    세번째 시도 : 200000까지 잡은 배열 활용
    성공
    생각해보니 가능한 최대 범위가 100000*2까지였다 (입력 범위가 100000)
    또한 최소 범위는 0이다.
    -1이 나왔다는 거는 0보다 아래로 갔다는 건데,
    자연수 범위에서 -1에서 양수로 가려면 1을 더하는 방법 밖에 없으므로
    다시 비효율적으로 0으로 올라가는 경우의 수밖에 없다.
    그리고 무엇보다 음수에서 2배는 음수다...

    이렇게 가능한 범위를 냉정하게 생각해보니 풀렸다...

*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

bool arr[200001];

bool isRange(int n) {
    return n >= 0 && n <= 200000;
}

int BFS(int n, int k) {
    queue<int> q;

    q.push(n);
    int t = 0;
    int val = n;

    while (val != k) {
        int size = q.size();

        ++t;
        for (int i = 0; i < size; ++i) {
            int p = q.front();
            q.pop();

            if (p + 1 == k || p - 1 == k || p * 2 == k) {
                val = k;
                break;
            }

            if (isRange(p + 1) && !arr[p+1]) {
                q.push(p + 1);
                arr[p + 1] = true;
            }
            if (isRange(p - 1) && !arr[p - 1]) {
                q.push(p - 1);
                arr[p - 1] = true;
            }
            if (isRange(p * 2) && !arr[p * 2]) {
                q.push(p * 2);
                arr[p * 2] = true;
            }
        }
    }
   
    return t;
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

   
    int  t = BFS(n, k);

    cout << t;
}


