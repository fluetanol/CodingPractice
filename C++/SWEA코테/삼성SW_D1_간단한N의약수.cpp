// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1간단한N의약수
// 24/04/21
// 2분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        if (T % i == 0)
            cout << i << " ";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//생략