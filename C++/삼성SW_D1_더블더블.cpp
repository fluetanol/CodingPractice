// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1더블더블
// 24/04/21
// 2분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int v = 1;
    int T;
    cin >> T;

    cout << v << " ";
    for (int i = 0; i < T; i++)
    {
        v *= 2;
        cout << v << " ";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//생략