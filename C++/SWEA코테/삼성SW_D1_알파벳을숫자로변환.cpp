// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1알파벳을숫자로변환
// 24/04/21
// 2분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    string T;
    cin >> T;
    for (int i = 0; i < T.length(); i++)
    {
        cout << T[i] - 'A' + 1 << " ";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//너무 쉬워서 패스
