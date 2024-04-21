// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2간단한소인수분해
// 24/04/21
// 10분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cout << "#" << test_case << " ";
        int k;
        cin >> k;
        int arr[5] = {2, 3, 5, 7, 11};
        int idx = 0;
        int count = 0;
        while (idx != 5)
        {
            if (k % arr[idx] != 0)
            {
                cout << count << " ";
                count = 0;
                idx++;
                continue;
            }
            else
            {
                count++;
                k /= arr[idx];
            }
        }
        cout << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//단순 구현 문제
//나머지가 0이 나오기 전까지 계속 나눠주면 됨
//문제 특성상 반드시 2,3,5,7,11의 곱으로만 표현 가능한 숫자가 나올 수 밖에 없으므로
//2로 계속 나눠주다가 못나누면 3, 또 못나누면 5... 이렇게 이어서 나눠주면 된다.