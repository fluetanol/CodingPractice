#include <iostream>
#include <vector>

using namespace std;

//1버전 : 시간 880ms 길이 : 580B
int main()
{
    int n, l;
    cin >> n >> l;

    int min = 999;
    int mfront = 0;
    int mback = 0;
    int front = 0;
    int back = 0;
    long sum = 0;

    while (back <= n + 1)
    {
        if (sum < n)
        {
            sum += back;
            back++;
        }
        else if (sum >= n)
        {
            if (sum == n && (min > (back - front) && (back - front) >= l))
            {
                min = (back - front);
                mfront = front;
                mback = back;
            }
            sum -= front;
            front++;
        }
    }

    if (mback - mfront == 0 || mback - mfront > 100)
        cout << -1;
    else
    {
        for (int i = mfront; i < mback; i++)
            cout << i << " ";
    }
}
/*
투포인터를 이용해서 앞뒤에서 더하고 뺴는 방식
O(n)정도의 시간이 걸린다.
나쁘지 않지만 이보다 수학적으로 더 빨 리 풀수 있는 방법이 있으니...
*/


//2버전  : 시간 0ms, 길이 341b

using namespace std;

int main()
{

    int n, l;
    cin.tie(0);
    cin >> n >> l;

    for (double k = l; k <= 100; k++)
    {

        double a = (n - ((k - 1) * k / 2)) / k;

        if (a < 0)
            break;
        else if (a - (int)a == 0)
        {
            for (int i = a; i < a + k; i++)
                cout << i << " ";
            return 0;
        }
    }

    cout << -1 << " ";
    return 0;
}

/*
    공차가 1인 등차수열의 합을 잘 이용하면 된다.
    길이가 l인 등차수열의 합을 보자

    l = 2이고, 초항이 a라면
    a + a+1 = 2a+1
    l=3이면, a+a+1+a+2 = 3a+3
    l=4이면, a+a+1+a+2+a+3 = 4a+6
    ...
    l=k이면, a + a+1 + a+2 + ... + a+k-1 = ka + k(k-1)/2

    이를 이용하면
        n = ka + k(k-1)/2
    식이 세워지고, 우리가 궁금한 값은 a이므로 a에 대해 정리하면
        a = (n - k(k-1)/2) / k

    이 된다.

    문제의 조건에 따라 a는 음이 아닌 정수여야 하며, l <=100이여야 하므로
    for문으로 l을 2부터 100까지 돌려서 저 식에 대입해서 a를 구하면 된다.

    n을 만들수 있는 l개의 등차수열을 찾으면 a ~ a+l까지 출력하면 된다...

    다만 위 방식의 위험한 점은  (n - ((k - 1) * k / 2)) / k; 이 식을 한번에 처리해서
    k로 나누는 과정에서 소수점 오차 문제로 큰 수에 대해선 부정확한 문제가 생길수 있다.
    그래서 안전한 값을 도출하고 싶으면 double로 해야 하긴하나,
    만약 n값이 9999999999999999999999같이 엄청 큰 수라면 저 형태도 틀리는 케이스가 있을 수 있다.
    더 안전하게 계산하는 방법이 없을까?
*/


//3버전 : 시간 0ms, 길이 365b
using namespace std;

int main()
{

    int n, l;
    cin.tie(0);
    cin >> n >> l;

    for (int k = l; k <= 100; k++)
    {
        int a = (n - ((k - 1) * k / 2));

        if (a % k != 0)
            continue;
        if (a < 0)
            break;
        else
        {
            a = a / k;
            for (int i = a; i < a + k; i++)
                cout << i << " ";
            return 0;
        }
    }

    cout << -1 << " ";
    return 0;
}

//방법은 위 식에서 확실히 정수로 나올 부분을 걸러내면서
//소수점이 나오는 케이스를 건너 뛰면 되는 것이다.

// 다시 말하지만        a = (n - k(k-1)/2) / k에서
// 문제 조건에 따라 a는 "정수" 여야 한다.
// k(k-1)/2는 홀수 * 짝수 형태로 2로 나눠도 항상 정수가 나온다는 보장이 되므로
// 실수가 되냐 정수가 되냐를 판가름 하는 부분은 " / k ", 즉 k로 나누는 부분이다.
// 이를 이용해서
/*
        int a = (n - ((k - 1) * k / 2));
        먼저 이렇게 k로 나누기 전값을 저장해두고(무조건 정수가 나오리라는 보장이 있음)

        if (a % k != 0)
            continue;
        그 다음 이렇게 나누어 떨어지지 않는 케이스에 대해선 넘기며

        else 
        {
            a = a / k;
        }
        이렇게 나누어 떨어지는 케이스에 대해서만 나누어 떨어진 값을 a에 저장해서 출력하면
        복잡하게 float나 double을 쓰지 않고 int만 써서도 풀 수 있다.
        
        수학 수식을 쓸 때는 되도록 정수형으로 나누어 떨어질 수 있는지 분석 좀 해서
        안전하게 풀 수 있는 방법을 찾아보도록 하자.
        물론 꼭 그러라는 건 아니고 어차피 코테는 시간싸움이니 
        그냥 double, long갈기면서 사나이처럼 풀어도 됨
        근데 팀 플젝이나 실무에서 이러면 혼날듯
*/
