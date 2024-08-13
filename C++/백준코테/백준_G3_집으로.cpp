// 문제번호 : 1069번
// 집으로
// 푼 시간 : 3시간
// 알고리즘 분류 : 수학, 기하학, 애드혹

#include <iostream>
#include <cmath>


using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed;
    cout.precision(12);

    double x, y, d, t;
    cin >> x >> y >> d >> t;

    // case1
    // 그냥 대각선으로 걷는 경우
    double dist = sqrt(pow(x, 2) + pow(y, 2));

    // case2
    // jump로 갈만큼 가고 나머지 거리를 걷는 경우
    int jumpcount = dist / d;
    double rest = dist - (d * jumpcount);
    double case1 = jumpcount * t + rest;

    // case3;
    // jump로 갈만큼 간 거리에서 한번 더 간 뒤에 back해야 하는 거리를 걷는 경우
    jumpcount++;
    rest = (d * jumpcount) - dist;
    double case2 = jumpcount * t + rest;

    // case4
    // jump의 방향벡터를 교묘하게 설정하였을때 가능한 최소 횟수
    if (jumpcount == 1)
        jumpcount++; // 단, jumpcount가 0인 케이스,
    // 즉 d가 전체 거리보다 큰 경우는 최소 2번으로 가정함
    double case3 = jumpcount * t;

    double minv = min(case1, case2);
    minv = min(case3, minv);
    minv = min(minv, dist);

    cout << minv << endl;
}


// 그냥 문제 특성을 따져보며 그 문제에 맞는 풀이법을 만들어야 하는 문제다.
// 이를 애드혹 문제라고 한다.
// 정형화된 알고리즘(BFS, DFS, 그리디 등)같은 알고리즘이 아니라 
// 정말 그 문제에 맞는 풀이와 그에 따른 최적화를 거쳐야 하는 문제로
// 쉽게 말하면 창의력과 센스가 좋아야 하는 문제다...

// 마땅한 공략법도 없기 때문에 그냥 많이 풀어보기나 하자

/*

    문제의 풀이는 다음과 같다.

    1. 그냥 (X,Y)을 향해 걷기만 하는 경우 (보통 점프해서 가는 게 더 구린 경우 이게 정답이다)
    2. (X,Y)을 향해 점프해서 최대한 가고 나머지 거리는 걷는 경우 (일반적이고 직관적인 정답이다)
    3. (X,Y)을 향해 점프해서 가되, 최대한 갈 수 있는 거리보다 한 번 더 가고 남은 거리를 걷는 경우
    (2번으로 걸어가는 거리보다 3번으로 걸어가는 거리가 더 짧은 특이 케이스.
    현재 위치로부터 (X,Y)까지의 거리보다 현재 위치+점프거리로부터 (X,Y)까지의 거리가 더 짧은 경우이다
    원을 직접 그려가면서 해보면 이해됨)

    **********4. 그냥 교묘한 각도조절을 통해 점프만으로 (X,Y)에 도달하는 경우
    이 4번 케이스가 가장 까다로운데
    직관적으로는 "가능하겠다" 라는 걸 알아도 진짜 모든 케이스에 대해서 가능한지,
    그리고 그 최소 횟수가 무엇인지 증명해내는게 쉽진 않기 때문이다.

    최소횟수를 결론부터 말하면 다음과 같은데

     1) d가 전체 거리보다 작은 경우 : 대각선 방향으로 최대한 가는 횟수 + 1
     2) d가 전체 거리보다 큰 경우 : 2

    이 대략적인 증명은 notion에 정리해둠

    위 네가지 케이스에 대한 횟수들 중 최솟값이 그냥 정답이다.
    1~3번은 30분내로 생각이 가능하지만 
    4번은 직관적으로 이해는 해도 상당히 찝찝해서 고민하게 됨
    문제 푸는 시간이 저렇게 늘어난 이유도 이 4번부분에 대한 증명을 찾아보려고 소모된게 컸다.
*/