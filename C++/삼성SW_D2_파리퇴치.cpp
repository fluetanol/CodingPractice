// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2파리퇴치
// 24/05/16
// 1140

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
        int n, k;
        cin >> n >> k;

        vector<vector<int>> v(n);
        vector<vector<int>> v2(n);

        for (int i = 0; i < n; i++)
        {
            vector<int> t(n);
            v2[i] = t;
            for (int j = 0; j < n; j++)
            {
                int t;
                cin >> t;
                v[i].push_back(t);
            }
        }

        // 첫번째 케이스
        int max = -1;
        int sum = 0;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
                sum += v[i][j];
            if (max < sum)
                max = sum;
        }
        v2[k - 1][k - 1] = sum;

        // 한 줄 읽기 케이스
        for (int i = k; i < n; i++)
        {
            int sum = v2[k - 1][i - 1];
            for (int j = 0; j < k; j++)
            {
                sum += v[j][i] - v[j][i - k];
            }
            v2[k - 1][i] = sum;
            if (max < sum)
                max = sum;
        }
        // n줄 읽기 케이스
        for (int t = 0; t <= n - k; t++)
        {
            for (int i = k; i < n; i++)
            {
                int sum = v2[i - 1][t + k - 1];
                for (int j = t; j < t + k; j++)
                {
                    sum += v[i][j] - v[i - k][j];
                }
                v2[i][t + k - 1] = sum;
                if (max < sum)
                    max = sum;
            }
        }
        cout << "#" << test_case << " " << max << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
내가 푼 방식은 쌩 어거지로 푼 O(n^2 + mn)정도의 성능인데, 사실 이 풀이도 그렇게 느린 방식은 아니다만
로직이 난해하고 일관성이 없다...

더 효율적인 아래 누적합을 이용한 dp풀이방법이 정석적이다.
중요하니 꼭 파악해두자

board = new int[m][m];
prefixSum = new int[m + 1][m + 1];
int max = Integer.MIN_VALUE;
for (int i = 0; i < m; i++)
{
    board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
}
for (int i = 1; i < m + 1; i++)
{
    for (int j = 1; j < m + 1; j++)
    {
        prefixSum[i][j] = board[i - 1][j - 1] + prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];
    }
}

for (int i = 1; i <= m - n + 1; i++)
{
    for (int j = 1; j <= m - n + 1; j++)
    {
        int sum = prefixSum[n + i - 1][n + j - 1] - prefixSum[n + i - 1][j - 1] - prefixSum[i - 1][n + j - 1] + prefixSum[i - 1][j - 1];
        max = Math.max(sum, max);
    }

}


해설
처음볼때 상당한 난이도의 로직이니까 확실히 이해할 필요가 있다.

5 2
1 3 3 6 7
8 13 9 12 8
4 16 11 12 6
2 4 1 23 2
9 13 4 7 3


1  4  7  13 20
9  25 37 55
13 45 68 98
15 51 75 128

위 표는 누적합을 하되, 1차 중복된 요소만 제거시킨 합의 모음이다.
가령 0행 0열의 가로는 1,4,7... 세로는 1,9,13... 이렇게 단순 누적하면 되지만
이 둘을 합친 A행 B열(A>0, B>0)은 [1,1]을 기준으로 보면
4 + 9 + 13 = 26이 되어야 한다.
이때 4, 9에는 각각 1이 중복으로 더해지므로 1을 빼주는 작업을 한다.

비슷하게 [1,2]라면 25+7+9 - 4로 25, 7  각각에 중복으로 합쳐진 것을 제외 시켜준다...
참고로 그런식으로 누적합을 하기 위해선

1. 0행일떈 단순 가로 누적을 함.
2. 1행부터 [a,b]의 누적합은
sum [a,b] = [a-1, b] + [a,b-1] + [a,b] - [a-1,b-1]
(여기서 [a,b]는 해당 위치가 아직 더해지기 전의 [a,b]값, 이를 위해 누적합을 할땐
원행렬이 아닌 따로 비워져 있는 별도의 공간에다가 값을 저장해둬야 한다)

방식으로 해둔다.


이후 2차 중복을 걸러낸다. 이는 크기 M에 따라 갈린다. 가령,
[1,2]라면 직관적으로 앞에 있는 1열은 의미 없음을 알 수 있다.
여기서 25+7+9-4라는 작업을 할때, 유효한 숫자는 이렇다

25 7 9
1 8 4 13 4 3 9
여기서 4는 아까 중복제외 작업으로 빼줬으니 하나 뺴보면
1 8 13 4 3 9
여기서 4는 또 1 3으로 해체가 가능하다
1 8 13 1 3 9
근데 이중 1열 출신 성분들을 뽑아보면
1 8
이 두놈이 생긴다.
1+8=9인데, 이는 곧 [1,0]위치에 있는 성분이다.
즉, 만약 [A,B]가 범위 특성상 B-M열만 제외시켜야 한다면
[A, B-M]을 빼주면 된다는 걸 유추해볼 수 있다.

비슷한 논리로, A-M행만 제외시켜야 한다면 [A-M, B]를 빼준다.


그런데 여기서 행과 열 둘다 빼줘야 하는 경우를 생각해보자


1 3 3 6
8 13 9 12
4 16 11 12
2 4 1 23


1  4  7  13
9  25 37 55
13 45 68 98
15 51 75 128

에서 [2,2]를 생각해본다면
유효한 범위는 13 9 16 11이 네가지이므로 0행, 0열의 정보가 의미없음을 알 수 있다.
우리가 위에서 발견한 규칙 대로라면 아마
68 - 7 - 13을 하면 된다는 것을 알 수 있을 것이다
([2,2] - [2,0] - [0,2])
그런데 사실 우리는 저 누적합 특성상 7과 13은 1이 공통으로 또 포함되어있음을 알고 있다... 즉,
지울 행과 지울 열의 교차점이 두번 빼지므로 한번은 다시 더해주는 작업을 해야한다. 즉,
[2,2] - [2,0] - [0,2] + [0,0]

이를 일반화 시켜보자. 어떤 위치 a,b에서 크기 m일때의 합은

sum(m)[a,b] = [a,b] - [a-m,b] - [a,b-m] + [a-m,b-m]
이다...

위 예시에서는 0행일떄의 경우도 일반화시키기 위해서 n+1크기로 0행 0열을 마진행렬로 남겨두는 방식으로 풀었다.
정말 똑똑한듯


이제
 prefixSum[i][j] = board[i - 1][j - 1] + prefixSum[i][j - 1] + prefixSum[i - 1][j] - prefixSum[i - 1][j - 1];

 int sum = prefixSum[n + i - 1][n + j - 1] - prefixSum[n + i - 1][j - 1] - prefixSum[i - 1][n + j - 1] + prefixSum[i - 1][j - 1];



이 두개 식을 이해하겠는가...?
하...










*/