// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3육십갑자
// 24/05/10
// 25분

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
        int n, m;
        vector<string> vn, vm;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            vn.push_back(s);
        }
        for (int j = 0; j < m; j++)
        {
            string s;
            cin >> s;
            vm.push_back(s);
        }

        int count = 0;
        string t = vn[0] + vm[0];
        vector<string> vc;
        while (true)
        {
            vc.push_back(vn[count % vn.size()] + vm[count % vm.size()]);
            count++;
            if (t == vn[count % vn.size()] + vm[count % vm.size()])
                break;
        }

        int k;
        cin >> k;
        cout << "#" << test_case << " ";
        for (int i = 0; i < k; i++)
        {
            int kk;
            cin >> kk;
            cout << vc[(kk - 1) % count] << " ";
        }
        cout << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//주기가 아주 큰 수가 아니기도 하고 어차피 어떤 주기에 어떤 값이 와야 하는지 미리 기록도 해둬야 하는 문제여서
//수학적 계산 없이 직접 반복문으로 규칙에 맞게 1회차 돌려보면서 한 주기에 어떤 이름이 지어지는지 배열에 저장했다.
//이후 주어지는 값에 대응되는 주기의 이름을 꺼내서 출력하면 된다. (나머지 연산 쓰면 됨)
//그건 그렇고 입력처리가 정말 귀찮았던 문제...