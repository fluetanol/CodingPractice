// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3원안의점
// 24/04/28
// 15분

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    int x, y;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        int count = 0;
        cin >> n;
        for (int i = -n; i <= n; i++)
        {
            x = i;
            for (int j = -n; j <= n; j++)
            {
                y = j;
                int circle = x * x + y * y;
                if (circle <= n * n)
                    count++;
            }
        }
        cout << "#" << test_case << " " << count << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//x^2+y^2 <= n^2
//이 식 그대로 조건문 걸어서 만족하면 count시키면 되는 문제
//반지름이 n이므로 확인해야 할 전체 범위는 -n~n까지임 (0,0)이 중심이여서.

//그래봤자 O(n^2)이고 표본도 n=200이 끝이니 여기서 끝내도 됨.