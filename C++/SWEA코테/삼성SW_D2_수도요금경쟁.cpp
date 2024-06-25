// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2수도요금경쟁
// 24/04/21
// 15분

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
        int k;
        int idx = 0;
        int arr[5];
        while (iss >> k)
        {
            arr[idx] = k;
            idx++;
        }
        cout << "#" << test_case << " ";
        // 이번에 사용한 물양
        int W = arr[4];
        // 달당 요금
        int P = arr[0];
        // 기본 요금
        int Q = arr[1];
        // 기본 요금 상한선
        int R = arr[2];
        // 추가 요금
        int S = arr[3];

        if (W <= R && P * W < Q)
            cout << P * W;
        else if (W <= R && P * W >= Q)
            cout << Q;
        else if (W > R && P * W < Q + (W - R) * S)
            cout << P * W;
        else if (W > R && P * W >= Q + (W - R) * S)
            cout << Q + (W - R) * S;

        cout << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}


//단순 구현 문제여서 구현만 잘해도 맞는 문제다
// 케이스가 네가지로 나뉘는데

// 1. B사 기본요금선 아래인데 A사가 더 싼 경우
// 2. B사 기본요금선 아래인데 B사가 더 싼 경우
// 3. B사 기본요금선 위인데 A사가 더 싼 경우
// 4. B사 기본요금선 위인데 B사가 더 싼 경우

//그냥 이 조건대로 조건 세워서 요금 출력해주면 된다.