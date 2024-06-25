// https://school.programmers.co.kr/learn/courses/30/lessons/135808
// 프로그래머스_lv1과일장수
// 24/06/15
// 10분

#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score)
{
    int answer = 0;
    vector<int> count(1000001);

    for (auto i : score)
        count[i]++;

    int idx = k;
    int cnt = 0;
    while (k != 0)
    {
        if (count[k] != 0)
        {
            count[k]--;
            cnt++;
        }
        else if (count[k] == 0)
            k--;

        if (cnt == m)
        {
            answer += (k * m);
            cnt = 0;
        }
    }
    return answer;
}



//카운트 정렬을 이용해서 푼 문제
//주어진 score의 최대 길이가 1,000,000이라서 복잡도가 엄청 커지지 않을 거라는 생각이 들었다.
//그리고 어차피 점수 최댓값은 k임

/*
    풀이를 간단히 정리해보자면, 최대 이익을 얻기 위해선 가장 높은 점수를 m개씩 골라가면서,
    그렇게 고른 m개 중의 (최솟값) * (m개)를 더해주면 되는 것.

    가령 1 3 4 5 6 3 3 2 라는 score가 있고, m = 3이라고 한다면
    1. 6 5 4 를 골라 4 * 3 = 12
    2. 3 3 3 을 골라 3 * 3 = 9
    3. 남은 점수는 1,2밖에 없는데 이는 m=3을 만족할 수 없으므로 무시

    따라서 12 + 9 = 21이 답이 된다.

    count배열의 k번째 항부터 들어있는 원소 갯수를 m개를 고를때 까지 마이너스 해주고,
    만약 m개를 고르기 전 k번째 항의 원소 갯수가 0이 된다면 그 아래 k-1번째 항의 원소 갯수를 또 확인한다.
    =>
        if (count[k] != 0)
        {
            count[k]--;
            cnt++;
        }
        else if (count[k] == 0)
            k--;

    여기서 자명한 것은, 만약 m개를 모두 세었을 때 그 때의 k값은 고른 m개의 수중 최솟값이 된다는 것이므로
    그때 k * m을 answer에 더해주면 된다 (위에 나온  (최솟값) * (m개))
    =>
        if (cnt == m)
        {
            answer += (k * m);
            cnt = 0;
        }

    이 짓을 k = 0이 될 때까지 반복해주면 된다.
    어차피 남은 점수들이 m개를 채우지 못하면 answer에 카운트 되지 않게 되므로 별도의 조건문은 없어도 됨.
*/

//이 문제도 lv1문제 치곤 좀 머리 쓰는 문제였음 ㅋㅋ