// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1평균값구하기
// 24/04/19
// 10분

#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    cin.ignore();
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        getline(cin, s);
        istringstream iss(s);
        int n;

        float avr = 0;
        while (iss >> n)
        {
            avr += n;
        }
        avr /= 10;
        avr = round(avr);
        cout << "#" << test_case << " " << avr << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//D1문제들은 쉬운 문제라 그냥 넘어감
//근데 삼성 아카데미 쪽 문제는 백준과 비슷하게 입출력을 해야하므로...
//입력에 대한 팁을 몇 개 적어봄

//1. 띄어 쓰기 단위로 읽을 땐 cin이 좋음
//2. 한 줄 단위로 읽을 땐 getline()을 쓰면 됨
//3. 입력 받은 숫자 string을 빠르게 캐스팅 하고 싶다면 istringstream이 유용함.

//추가로 반올림, 올림, 내림 함수는 각각 round, ceil, floor고 
//<cmath> 인클루드 시키면 됨

//암만봐도 입출력 알아서 처리해주는 프로그래머스가 좋다니까

//