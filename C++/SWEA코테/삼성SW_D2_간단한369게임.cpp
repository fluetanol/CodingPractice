// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2간단한369게임
// 24/04/24
// 15븐

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
    int i;
    int T;

    cin >> T;

    for (i = 1; i <= T; ++i)
    {
        string k = to_string(i);
        string clap = "";
        for (auto s : k)
        {
            if (s == '3' || s == '6' || s == '9')
                clap += "-";
        }
        if (clap == "")
            cout << k << " ";
        else
            cout << clap << " ";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//또 겁나 쉬운 d2문제
//string으로 치환해서 하나씩 다 뜯어보는게 좋다.
//아니면 find써도 됨.

