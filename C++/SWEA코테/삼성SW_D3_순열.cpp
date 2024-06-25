// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3순열
// 24/05/04
// 20분

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
        int n;
        cin >> n;
        vector<int> v(n);
        string yn = "Yes";
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            v[k - 1] += 1;

            if (v[k - 1] > 1)
                yn = "No";
        }
        cout << "#" << test_case << " " << yn << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//그냥 자료가 두번 반복되는지 확인만 하면 되는 가짜 순열 문제
//동적할당은 뭔 오류가 터질지 모르는 폭탄이라서 vector씀