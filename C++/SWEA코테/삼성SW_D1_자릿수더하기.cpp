// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1자릿수더하기
// 24/04/19
// 10분

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int answer;
    string T;
    cin >> T;
    for (int i = 0; i < T.length(); i++)
    {
        answer += (T[i] - '0');
    }
    cout << answer;
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//c++에서도 string의 각 문자를 접근하면 char로 자동 전환됨
//이 특성 이용하면 손쉽게 숫자 전환도 할 수 있다.
