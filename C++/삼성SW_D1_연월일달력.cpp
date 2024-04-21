// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d1연월일달력
// 24/04/19
// 15분

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        string sy = s.substr(0, 4);
        string sm = s.substr(4, 2);
        string sd = s.substr(6, 2);

        int y = stoi(sy);
        int m = stoi(sm);
        int d = stoi(sd);

        cout << "#" << test_case << " ";
        if (m > 12 || m <= 0)
            cout << -1 << endl;
        else if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31)
            cout << -1 << endl;
        else if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
            cout << -1 << endl;
        else if (m == 2 && d > 28)
            cout << -1 << endl;
        else
            cout << sy << "/" << sm << "/" << sd << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//오늘의 c++상식
//1. stoi(include <string>)은 string을 int로 변환시킴
// 재밌는건 마지막 인자에 넣은 숫자가 변환할 진수로,
// 2를 넣으면 2진수로 변환도 가능;;

// 2. substr은 (include <string>)했을 시 따라오는 부분 문자열 가져오는 함수
// substr(시작지점, 시작지점으로 부터 몇개의 문자를 가져올지) 로 쓰면 됨
