// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3이진수표현
// 24/04/26
// 30분

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    string s;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, m;
        cin >> n >> m;

        int checkbit = 0b1;
        string sbinary = "";
        string onoff = "ON";
        for (int i = 0; i < n; i++)
        {
            if (m & checkbit) {}
            else
            {
                onoff = "OFF";
                break;
            }
            checkbit = checkbit << 1;
        }
        s += "#" + to_string(test_case) + " " + onoff + "\n";
    }
    cout << s;
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//에라이
//실수와 최적화 문제때문에 계속 시간 초과나 몇 개 케이스에서 삑살난 문제

//우선 이런 이진수 문제는 비트연산으로 푸는게 가장 행복하다.
//비트 연산은  (m & 0b1 << 1) 을 n회 반복하는 식으로.

//맨 아래 n개의 비트가 0이 하나라도 나오면 off상태이고,
//위 방식대로면 아랫 비트부터 차례대로 2진수를 구하는 방식이므로
//총 n번의 반복을 돌면서 off가 되는 경우를 걸러낸다.
//만약 0이 한번이라도 나온다면 break하고 off,
//한번도 안나왔다면 반복이 끝까지 돌고 그냥 on을 출력하면 된다.

//내가 이 문제 계속 절었던 큰 원인이
//on인 경우에 그냥 continue하면서 계속 반복 돌으라고 한거 때문이였는데
//그때문에 밑에 있는 bit shift연산을 무시하고 다음 반복으로 넘어갔었다...
//그냥 처음부터

/*
            if(! (m&checkbit)) {
                onoff = "OFF";
                break;
            }
            checkbit = checkbit<<1;
            */

//이렇게 했더라면...!