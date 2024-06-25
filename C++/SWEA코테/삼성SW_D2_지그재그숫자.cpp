// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2숫자를정렬하자
// 24/04/24
// 5분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    int arr[2] = {-1, 1};
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k;
        cin >> k;
        int sum = 0;
        for (int i = 1; i <= k; i++)
        {
            sum += i * arr[i % 2];
        }

        cout << "#" << test_case << " " << sum << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//너무 쉬운데 이왜 D2?
//D2내에서도 난이도편차 좀...