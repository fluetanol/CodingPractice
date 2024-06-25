// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3구구단1
// 24/04/26
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
        int n;
        cin >> n;

        string isTrue = "No";
        for (int i = 1; i <= 9; i++)
        {
            if (n % i == 0 && n / i >= 1 && n / i <= 9)
            {
                isTrue = "Yes";
                break;
            }
        }

        cout << "#" << test_case << " " << isTrue << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//왜 레벨 3인거임 이게?

