// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3큰수의최대공약수
// 24/05/10
// 30분

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string a, b;
        cin >> a >> b;
        if (a == b)
            cout << "#" << test_case << " " << a << endl;
        else
            cout << "#" << test_case << " " << 1 << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//너무 어렵게 생각해서 이게 맞나 싶었던 문제...

//어이없게도 두 수의 최대공약수가 아닌 두 수 사이의 모든 수에 대한 최대공약수 문제인데
//연속된 두 수의 공약수는 사실상 없기 때문에 정답은 1밖에 없으며
//두 수가 같을 때나 자기 자신이 곧 최대공약수이다...