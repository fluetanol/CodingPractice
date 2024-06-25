// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3Flatten
// 24/05/17
// 45분

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        vector<int> v(100);
        int n;
        cin >> n;
        int min = 999, max = -1;
        for (int i = 0; i < 100; i++)
        {
            int k;
            cin >> k;
            if (min >= k)
                min = k;
            if (max <= k)
                max = k;
            v[k]++;
        }

        int count = 0;
        while (true)
        {
            int vmin = v[min];
            for (int i = 0; i < vmin; i++)
            {
                if (v[max] != 0)
                {
                    v[max]--;
                    v[max - 1]++;
                    v[min]--;
                    v[min + 1]++;
                    count++;
                    if (count > n)
                        break;
                }
                if (v[max] == 0)
                    max--;
            }
            if (count > n)
                break;
            min++;
        }
        cout << "#" << test_case << " " << max - min << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        vector<int> v(100);
        int n;
        cin >> n;
        int min = 999, max = -1;
        for (int i = 0; i < 100; i++)
        {
            int k;
            cin >> k;
            if (min >= k)
                min = k;
            if (max <= k)
                max = k;
            v[k]++;
        }

        int count = 0;
        while (true)
        {
            int vmin = v[min];
            for (int i = 0; i < vmin; i++)
            {
                if (v[max] != 0)
                {
                    v[max]--;
                    v[max - 1]++;
                    v[min]--;
                    v[min + 1]++;
                    count++;
                    if (count > n)
                        break;
                }
                if (v[max] == 0)
                    max--;
            }
            if (count > n)
                break;
            min++;
        }
        cout << "#" << test_case << " " << max - min << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//부등호와 조건문 순서 차이로 자꾸 케이스 하나에서 삐꾸난 문제
//냉정하게 생각해보면 max값과 min값의 조절에 따라서 결과가 달라지기 때문에
//종료조건을 우선시 해야 하는 건 맞다...
//max값을 조절하는 v[max]==0 체크를 종료조건보다 먼저 했기 때문에
//특이한 케이스 하나에서 걸려든거 같은데
//진짜 너무하네...