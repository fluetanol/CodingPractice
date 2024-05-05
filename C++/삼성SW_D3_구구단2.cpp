// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3구구단2
// 24/05/05
// 3분

#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int a, b;
        cin >> a >> b;

        if (a >= 10 || b >= 10)
            cout << "#" << test_case << " " << -1 << endl;
        else
            cout << "#" << test_case << " " << a * b << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//왜 레벨 3이냐니까?
