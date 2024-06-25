// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3증가하는사탕수열
// 24/04/28
// 25분

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c < 3 || b < 2)
            cout << "#" << test_case << " " << -1 << endl;
        else
        {
            int count1 = 0;
            int tempb = b;
            if (b >= c)
            {
                count1 += b - c + 1;
                b = c - 1;
            }
            if (a >= b)
                count1 += a - b + 1;
            cout << "#" << test_case << " " << count1 << endl;
        }
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

// c->b->a순으로 내림 차순 정렬이 되어야 하므로
//c와 b의 간극을 줄이기 위한 연산과 그 이후 바뀐 b와 a의 간극을 줄이기 위한 연산을 해야 한다
//만약 c<=b라면, c>b가 되어야 하기 위한 최소 연산으로 b=c-1이 되어야 하고,
//따라서 b - c + 1만큼 사탕을 먹으면 c-1개가 된다.
//같은 방식으로 b와 a를 비교해서 b<a라면 a = b-1이 되도록 연산해주면 된다.

//한편 예외 사항으로 b>0, c>0이여야 하는데
//b = c-1이 되는 과정에서 c = 2라면 경우의 수는 c=2, b=1, a=0말곤 없다.
//즉  c<2인 케이스는 애초에 불가능한 문제
//또한, a= b-1이 되는 과정에서 b=1이라면 b=1, c=0이 되어야 하므로
//마찬가지로 b<1인 케이스도 불가능한 문제라고 볼 수 있다.
//이런 예외 케이스까지 걸러내면 풀리는 단순 구현 문제였다...