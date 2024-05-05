// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3조별과제
// 24/05/05
// 5분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;

        cout << "#" << test_case << " " << n / 3 << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//이게 왜 d3?????