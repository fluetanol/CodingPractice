// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3View
// 24/05/14
// 20분

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    for (test_case = 1; test_case <= 10; ++test_case)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int count = 0;

        for (int k = 2; k < n - 2; k++)
        {
            int max = -1;
            for (int i = k - 2; i <= k + 2; i++)
            {
                if (max < v[i] && i != k)
                {
                    max = v[i];
                }
            }
            if (v[k] - max > 0)
                count += v[k] - max;
        }
        cout << "#" << test_case << " " << count << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//양옆 거리 2까지의 건물들과 비교하는 문제
//즉, 하나의 건물에 대한 조망권을 확인하려면 양옆 4개의 건물들과
//비교를 해야하는데
//옆 건물들 중 가장 큰 건물이 현재 확인하려는 건물의 
//조망권을 좌우하기 때문에 
//사실상 부분 수열에 대한 최댓값을 구하는 문제와 다를바 없다.
//다행히 입력값이 1000정도로 그리 크지 않고 
//주어진 시간도 10초정도로 넉넉하니
//단순 반복문을 돌려서 구간별로 최댓값을 확인해주는 방식으로만 풀어도 통과되었다.
