// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3회문의회문
// 24/04/27
// 20분

#include <iostream>

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
        int len = s.length();
        int lenlen = (len - 1) / 2;

        int front = 0;
        int back = len - 1;
        int frontfront = 0;
        int backback = lenlen - 1;
        string yesno = "YES";
        while (true)
        {
            // cout << front <<" " << back << " " << frontfront << " " << backback <<endl;
            if (s[front] != s[back])
            {
                yesno = "NO";
                break;
            }
            if (s[frontfront] != s[backback])
            {
                yesno = "NO";
                break;
            }
            if (front != len / 2)
            {
                front++;
                back--;
            }
            if (frontfront != lenlen / 2)
            {
                frontfront++;
                backback--;
            }
            if (frontfront == lenlen / 2 && front == len / 2)
                break;
        }
        cout << "#" << test_case << " " << yesno << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//이전에 풀었던 초심자의 회문검사 문제를 잘 풀었다면
//사실상 이중 회문검사를 돌리면 되는 문제라서 그리 어렵진 않다
//한번의 while에서 바깥 회문을 검사하는 포인터(front)와
//안쪽 회문을 검사하는 포인터(frontfront)를 돌려가면서
//바깥과 안쪽 모두 회문임이라면 yes, 어느 한쪽이라도 아니면 바로 no로 탈출 해주면 된다.
