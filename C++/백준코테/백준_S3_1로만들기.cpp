// 문제번호 : 1463번
// 1로만들기
// 푼 시간 : 30분
// 알고리즘 분류 : DP, 메모이제이션
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void operation(int n, int count, vector<int> &v)
{
    if (n == 1)
    {
        if (v[n] > count)
            v[n] = count;
        return;
    }
    if (n % 3 == 0 && v[n] >= count)
    {
        v[n] = count;
        operation(n / 3, count + 1, v);
    }
    if (n % 2 == 0 && v[n] >= count)
    {
        v[n] = count;
        operation(n / 2, count + 1, v);
    }
    if (v[n] >= count)
    {
        v[n] = count;
        operation(n - 1, count + 1, v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n, count = 0;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 0; i < v.size(); i++)
        v[i] = 100;
    operation(n, count, v);

    cout << v[1] << endl;
}

/* 
   n에서 i로 내려가면서 벡터 안에 최솟값을 갱신해주는 방식.
   한번쯤은 n에서 i까지 내려가야 하는 수고가 있긴 하지만, 그래봐야 일반적으론 log타임 안엔 내려간다
   
   어떤 수 n을 거치면 몇번의 recursion (depth)를 돌았는지 기록 해주고, 1까지 도달했을 때 기록된 depth가 바로 연산횟수다.
   문제는 재귀적으로 돌다보니 n/3, n/2, n-1모든 케이스를 둘러봐야 하는 것인데, 반복적인 연산 낭비를 막기 위해서
   배열에 기록된 depth보다 현재 depth가 더 크다면 return, 그게 아니면 한번 그 방향으로 파고들어간다.

   이것만으로 엄청나게 recursion을 줄이면서 속도가 빨라진다.
   이 방법의 단점이라면, recursion자체의 물리적인 성능 문제도 있고,
   처음 배열을 특정 큰 수로 초기화 해줘야 한다는 것이다.

   좀 더 효율적인 방법은 없을까?
*/ 



//다른 유저의 풀이
int X;
int dp[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> X;

    // 2, 3은 1로 만드는데에 필요한 연산이 하나밖에 없는 의미없는 케이스
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;



    for (int i = 4; i <= X; i++)
    {
        //1을 빼는 경우
        dp[i] = dp[i - 1] + 1;

        //3으로 나누는 경우
        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
            dp[i] = dp[i / 3] + 1;

        //2로 나누는 경우
        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
            dp[i] = dp[i / 2] + 1;
    }

    //EX)10이라면
    /*
        0 1 1 0 0 0 0 0 0 0
        0 1 1 2 0 0 0 0 0 0   (dp[4] = dp[4-1]+1 = 2)
        0 1 1 2 3 0 0 0 0 0   (dp[5] = dp[5-1]+1 = 3)
        0 1 1 2 3 4 0 0 0 0   (dp[6] = dp[6-1]+1 = 4)
        0 1 1 2 3 2 0 0 0 0   (dp[6] = dp[6/3]+1 = 2 < 4) -> 갱신
        0 1 1 2 3 2 3 0 0 0   (dp[7] = dp[7-1]+1 = 3)
        0 1 1 2 3 2 3 4 0 0   (dp[8] = dp[8-1]+1 = 4)
        0 1 1 2 3 2 3 3 0 0   (dp[8] = dp[8/2]+1 = 3 < 4) -> 갱신
        0 1 1 2 3 2 3 3 4 0   (dp[9] = dp[9-1]+1 = 4)
        0 1 1 2 3 2 3 3 2 0   (dp[9] = dp[9/3]+1 = 2 < 4) -> 갱신
        0 1 1 2 3 2 3 3 2 3   (dp[10] = dp[10-1]+1 = 3)

        즉, 내 방식은 n에서 1이 되어가는 과정을 추적하는 방식이고
        이 방식은 1에서 n이 되어가는 과정을 추적하는 방식이다.
        초항 n = 1,2,3은 자명해서 0,1,1로 초기화를 시켜준다면 (최소 들어가야하는 고정 횟수)

        dp[i] = dp[i-1]+1, dp[i] = dp[i/2]+1, dp[i] = dp[i/3]+1 중 최소값을 dp[i]에 넣어주면 된다.
        달리말해서, i * 2와 i*3과 i+1 세 가지 케이스 중 어느 방향으로 가는 게 그 횟수가 가장 짧냐를 물어보는 것.

        memoization만 사용한게 내 방식이라면, 이 방식은 점화식까지 세워서 이전 기록을 연산에 잘 활용했기 때문에
        진정한 DP라고 볼 수 있다.

        추가로 스택 오버플로우를 생각하면 실제 거대한 INPUT에 대한 성능으로도 해당 방식이 더 좋을 것으로 예상됨.

        고정 O(n)의 시간복잡도로 해결하는 모습.
    */      

    cout << dp[X];
}