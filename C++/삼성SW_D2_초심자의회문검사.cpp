// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2초심자의회문검사
// 24/04/21
// 5분


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
        int isAns = 1;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != s[s.length() - 1 - i])
            {
                isAns = 0;
                break;
            }
        }
        cout << "#" << test_case << " " << isAns << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//굳이 문자열을 뒤집을 필요가 없다
//그냥 인덱스를 처음과 끝 인덱스에서 시작해서 
//반대 방향으로 문자를 보며 회문이 맞는지 체크하면 된다
//루프를 끝까지 돌았으면 회문이고
//못 돌고 중간에 탈락하면 회문이 아니인 방식.