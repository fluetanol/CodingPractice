// 문제번호 : 1300번
// k번째 수
// 푼 시간 : 20분
// 알고리즘 분류 : 수학

#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int *v = new int[k + 1]{};

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i * j < k)
                v[i * j] += 1;
        }
    }

    int idx = 1;
    while (true)
    {
        k -= v[idx];
        if (k <= 0)
            break;
        idx++;
    }
    delete[] v;
    cout << idx << endl;
}

//풀이 1. 카운트 정렬을 이용하는 기법
//시간 복잡도도 꽤 높고 공간 복잡도도 정말 높지만
//구현하나만큼은 정말 쉬운 기법


#include <iostream>
#include <algorithm>
using namespace std;

int divisorCount(int a, int n)
{
    int count = 0;
    for (int i = 1; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            int i2 = a / i;
            if (i2 <= n && i != i2)
                count += 2;
            else if (i2 <= n && i == i2)
                count++;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int tempk = k;
    int idx = 1;
    for (idx = 1; idx <= tempk; idx++)
    {
        k -= divisorCount(idx, n);
        if (k < 0)
            break;
    }
    cout << idx << endl;
}

//풀이 2
/*
    약수의 갯수를 하나씩 구하는 기법
    공간복잡도를 확실히 줄일 수 있고
    시간복잡도 또한 nsqrt(n)인 방법이지만 그럼에도 시간초과가 났다...
*/

#include <iostream>
#include <algorithm>
using namespace std;

int count(int n, int k)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        count += min(k / i, n);
    }
    return count;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int start = 1;
    int end = k;

    while (end - start > 1)
    {
        int counts = count(n, (start + end) / 2);

        if (counts < k)
        {
            start = (start + end) / 2;
        }
        else
        {
            end = (start + end) / 2;
        }
    }

    int a = count(n, start);
    int b = count(n, end);

    int ans = a < k ? end : start;

    cout << ans << endl;
}


//풀이 3
/*
    이분탐색을 이용한 방법
    
    우리가 구해야 할 값은 k번째에 올 수인데,
    i * j의 곱을 (1 <= i <= n, 1 <= j <= n)을 구하면 중복 수의 개수까지 포함하게 되어
    반드시 k보단 같거나 작은수가 k번째에 올 수라는 걸 추측해볼 수 있다.

    k번째에 올 수가 m이라고 생각해보면
    m보다 작은 수의 개수가 몇개인 지를 구하는 방법으로 접근해 볼 수 있는데, 
    이에 대한 식을 세우는 게 이 문제의 핵심이다.

    1 * j <= m이 된다고 하면, 가능한 모든 배수는 m / 1
    2 * j <= m이 된다고 하면, 가능한 모든 배수는 m / 2
    ...
    i * j <= m이 된다고 하면, 가능한 모든 배수는 m / i

    우리는 1~n까지의 가능한 배수들이 궁금하므로, 사실 m/ i가 n보다 커선 안된다는 사실도 유념하면
    sum(1~n, min (m / i , n)) >= k를 만족시키는 최소의 m을 찾으면 된다.

    부등식 범위 안에서 어떤 값을 찾는 문제니, 이분탐색을 쓰면 편리할 것이다.

    1 <= i <= k 범위 안에서, 중간값 (1+k)/2보다 작을 수 있는 i * j의 개수를 구하고,
    그것이 k보다 작다면 start값을 중간값으로, 크다면 end값을 중간값으로 바꾸면서
    start와 end가 같아질 때까지 반복하면 된다.

*/