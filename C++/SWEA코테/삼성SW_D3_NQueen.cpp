// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3NQUEEN
// 24/05/17
// 시간초과... (5/18에 풀음)

#include <iostream>
#include <vector>
using namespace std;

bool canPlace(int x, int c, vector<int> &v)
{
    if (c == 0)
        return true;
    for (int i = 0; i < c; i++)
    {
        if (v[i] == x || abs(c - i) == abs(x - v[i]))
        {
            return false;
        }
    }
    return true;
}

int NQueen(int n, int c, vector<int> &v)
{
    if (n == c)
    {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (canPlace(i, c, v))
        {
            v[c] = i;
            count += NQueen(n, c + 1, v);
        }
    }
    return count;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            v[i] = -1;
        cout << "#" << test_case << " " << NQueen(n, 0, v) << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//힌트를 참고해서 풀어봤는데
//결국 dfs를 써서 푸는 문제가 맞았었다.
//1차원 배열과 백트래킹 알고리즘만을 이용해서 풀 수 있는 문제였는데,
//1차원 배열엔 그 행의 몇번째 열에 퀸을 놨는지를 기록해두면 된다.

//사실 배치 불가능한 위치는 퀸의 이동이 대각선, 상하좌우방향이라는 간단하고 직관적인 이동이라서
//그 범위를 수학적으로 표현이 가능하다. 즉, 굳이 2차원 배열로 배치 불가능 위치를 기록해둘 필요가 없다는 것.

/*
    1.  상하좌우
    퀸의 위치가 a,b라면 a행, b열은 전부 배치 불가능 즉, (a,y), (x,b)는 배치 불가능.
    식으로 표현하면  b==y, a==x 는 배치 불가능

    2. 대각선
    퀸의 위치가 a,b일때, 그것의 대각방향의 좌표는 a+-i , b+-i로 표현 가능하다.
    만약 어떤 좌표 (c,d)가 (a+-i, b+-i)를 만족한다면 (+-는 플마,,,)

    a+-i = c, abs(i) = abs(c-a)
    b+-i = d, abs(i) = abs(d-a)

    따라서 abs(c-a) == abs(d-a) 는 배치 불가능
*/

/*
결국 이를 통해 우리가 알 수 있는 것은
dfs를 시도하는 타이밍은 내가 배치하려는 위치가 이전에 배치한 기물 위치를 수학적으로 계산 해봤을때,
종합적으로 배치 가능한 위치라는 게 확인 될때에만 dfs를 하면 된다는 것을 알 수 있다.

    for (int i = 0; i < c; i++)
    {
        if (v[i] == x || abs(c - i) == abs(x - v[i]))
        {
            return false;
        }
    }
     return true;

위에서 이 코드가 바로 그 기능을 나타내는데,
만약 c행의 x열에 배치하려 한다면 c행 이전에 배치한 기록들을 확인하여
단 한번의 경우에라도 다른 퀸에게 먹힐 수 있는 자리라면 바로 불가능한 자리임을 알리는 false를 반환하고
배치가 가능하다면 반복문을 거친 검역을 끝냈을 것이므로 반복문 이후 true를 반환시킨다.
예외적으로 c=0인 경우 어차피 첫번쨰 배치 위치이므로 어디에 놓든 상관 없어서

    if (c == 0)
        return true;

        라고 해줬음

*/

//결론적인 성능을 말하면 완전탐색임에도 꽤 빠른데,
//그 이유는 애초에 퀸 특성상 이동 가능한 칸 수가 존나 많기 때문에....
//퀸을 하나씩 배치할때마다 배치 가능한 칸 자체가 엄청 줄어들어서 dfs를 하는 횟수도 갈수록 크게 줄어든다...
//하지만 탐색 자체는 결국 전부 탐색이라서 N이 커질수록 지수적인 복잡도를 지니게 된다...

