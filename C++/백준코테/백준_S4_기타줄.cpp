// 문제번호 : 1049번
// 기타줄
// 푼 시간 : 20분
// 알고리즘 분류 : 그리디, 수학

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int pack, each;
    int minpack = 9999, mineach = 9999;
    for (int i = 0; i < m; i++)
    {
        cin >> pack >> each;
        if (minpack > pack)
            minpack = pack;
        if (mineach > each)
            mineach = each;
    }

    int case1 = (n / 6) * minpack + (n % 6) * mineach;
    int case2 = n * mineach;
    int case3 = ((n / 6) + 1) * minpack;

    int ans = case1 > case2 ? case2 : case1;
    ans = case3 > ans ? ans : case3;
    cout << ans;
}


//그리디 알고리즘 = 무식하게 현재 얻을 수 있는 가장 큰 이득을 취하는 방식

//최소 소비를 하고 싶다길래 최소 비용의 패키지, 최소 비용의 낱개 가격을 찾고 비교 우위를 따지면 되었다.

//따져볼 상황은 딱 세개였는데

// 1.그냥 낱개로 사는게 좋은 경우 ( n * mineach;)
// 2.패키지 +낱개 혼합으로 사는 경우 ( (n/6)*minpack + (n%6)*mineach;)
// 3.원래 사고자 하는 줄의 갯수를 넘겨서라도 패키지로 사는 게 좋은 경우 ( ((n/6)+1)*minpack;)

// 그래서 이 세 케이스 중 가장 최소가 되는 케이스를 고르면 정답이다.
