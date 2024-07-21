// 문제번호 : 6588
// 골드바흐의 추측
// 푼 시간 : 1시간
// 알고리즘 분류 : 수학, 정수론, 소수 판정, 에라토스테네스의 체

#include <iostream>
#include <vector>


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> v(1000001);

    for (int i = 2; i <= v.size() / 2; i++)
    {
        if (v[i] == false)
        {
            int j = 2;
            while (true)
            {
                if (i * j < v.size())
                {
                    v[i * j] = true;
                    j++;
                }
                else
                    break;
            }
        }
    }

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = n - 3; i > 2; i -= 2)
        {
            int a = n - i;
            int b = i;
            if ((!v[a]) && (!v[b]))
            {
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
        }
    }
}

// 어떤 수 n 한개만을 위해 소수를 판별하는 문제였다면
// root(n)까지 카운팅 해서 약수가 하나라도 있는지 확인하는 방법을 써도 되긴 했지만

// 이 문제는 여러 개의 n에 대해 소수를 판별해야 하고, 또 똑같은 n에 대한 소수 판별을 
// 여러번 해야 하기도 했으므로
// 차라리 소수를 미리 다 구해놓고, 그 소수를 이용해서 n을 만들어내는 방법을 사용하는게 나았다.


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;

        for (int i = n - 1; i > 1; i -= 1)
        {
            int a = n - i;
            int b = i;

            if ((a % 2 == 0 && a != 2) || (b % 2 == 0 && b != 2))
                continue;
            else if (a == 1 || b == 1)
                continue;

            bool primeA = true, primeB = true;
            for (int j = 2; j * j <= a; j++)
            {
                if (a % j == 0 && j != b)
                {
                    primeA = false;
                    break;
                }
            }
            for (int j = 2; j * j <= b; j++)
            {
                if (b % j == 0 && j != b)
                {
                    primeB = false;
                    break;
                }
            }

            if (primeA && primeB)
            {
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
        }
    }
}

// 위 방법은 골수까지 쥐어짜내서 최적화 시킨 
// 주어진 n값에 따라 동적으로 소수를 판별하는 방식인데
// 이 방식을 쓰면 O(nsqrt(n))의 시간복잡도를 가진다.

//그런데 에라토스테네스의 체를 쓰면 O(nloglogn)의 시간복잡도를 가진다.
//이는 nsqrt(n)보다 훨씬 더 빠른것으로 알려져 있으므로 (애초에 로그가 루트보다 복잡도 효율이 높음)
//에라토스테네스의 체를 쓰는게 더 좋은 방법이다.


/*
한번 정리해보자

에라토스테네스의 체 : nloglog(n)
- 장점 : 1~n까지의 소수를 전체적으로 빠르게 판별할 수 있다.
- 단점 : 굳이 전체를 파악할 필요 없이 한 두개의 숫자에 대한 소수를 판별할 땐 공간복잡도까지 잡아먹음

n개의 root(n) 소수 판별 : nsqrt(n)
- 장점 : 공간복잡도 효율이 좋으며, 범위가 모호한 어떤 수에 대해 소수를 판별할 때 효율적이다.
- 단점 : 여러 개의 n에 대한 소수 판별을 시작하면 에라토스테네스의 체보다 딸리는 건 어쩔수 없음

상황에 맞게 쓰도록....!


*/
