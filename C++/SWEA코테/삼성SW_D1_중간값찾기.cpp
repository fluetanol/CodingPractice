// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1중간값찾기
// 24/05/11
// 3분

#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    int v[T];
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> v[test_case - 1];
    }
    sort(v, v + T);
    cout << v[T / 2];
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}