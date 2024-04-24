// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3구독자전쟁
// 24/04/24
// 11분

#include <iostream>
#include <sstream>
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

        int arr[3];
        int idx = 0;
        int n;
        while (iss >> n)
        {
            arr[idx] = n;
            idx++;
        }

        int max, min;
        if (arr[1] < arr[2])
            max = arr[1];
        else
            max = arr[2];

        min = arr[1] + arr[2] - arr[0];
        if (min < 0)
            min = 0;

        cout << "#" << test_case << " " << max << " " << min << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
사실상 집합 교집합의 최댓값 최솟값 물어보는 문제다.
수학적인 특성을 알아두면 그냥 풀리는 문제
규칙은 다음과 같다

1. P+T <= N
최소 0
최대 P와 T중 더 작은 놈

2. P+T > N
최소 P+T - N
최대 P와 T중 더 작은 놈


이를 람다식으로 일반화 하면 이런 느낌이다.

min = P+T-N < 0 ? 0 : P+T-N;
max = P<T ? P : T;
*/