// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3등차수열만들기
// 24/05/03
// 10분

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int k = 2 * b - a - c;
        cout << fixed;
        cout.precision(1);
        cout << "#" << test_case << " " << abs((float)k / 2) << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
b-a = c-b
2b-a-c = 0

만약 2b-a-c가 0이 아닌 어떤 수 k가 나왔다고 치자.
(2b-a-c = k)

이는 다시 말해 a, b, c중 하나에 k를 빼면 등차수열을 만들 수 있다는 건데,
사실 위 식의 특성상 b는 두 번 포함되므로, 중간항 b는 k를 쪼개서 더해줘야 한다.
그니까 2(b+k)-a-c = 2b+2k-a-c이므로, k를 뺀게 아니라 2k를 뺀거랑 다름없다.
따라서 2(b+k/2) - a-c로 b에 x를 더할땐 k를 이등분 시켜야 한다는 것.

우리가 구해야 하는 x는 가장 작은 x값이다.
 a와 c에는 k를 그대로 더하지만, b에 더하면 k를 항상 1/2로 쪼갤 수 있으므로 
 항상 더 작은 x를 구할 수 있게 된다.
 이 원리를 이용하면 x = k/2임을 알 수 있다.
 또 수학문제야?
*/
