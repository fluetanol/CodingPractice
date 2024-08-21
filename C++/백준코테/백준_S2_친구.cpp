// 문제번호 : 1058번
// 친구
// 푼 시간 : 40분
// 알고리즘 분류 : 그래프 탐색, 플로이드 워셜 (다익스트라 알고리즘), 브루트포스

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string *s = new string[n];

    for (int i = 0; i < n; i++)
        cin >> s[i];

    int max = -1;

    for (int i = 0; i < n; i++)
    {
        vector<int> v(n);
        int count = 0;

        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;

            else if (s[i][j] == 'Y')
            {
                if (v[j] == 0)
                    count++;
                v[j] = 1;
                for (int k = 0; k < n; k++)
                {
                    if (i == k)
                        continue;
                    else if (s[j][k] == 'Y' && v[k] == 0)
                    {
                        v[k] = 1;
                        count++;
                    }
                }
            }
        }

        if (max < count)
            max = count;
    }
    cout << max;
}


//풀이 1. 그냥 브루트 포스

/*  
    depth가 2를 넘어가지 않는 친구 건너 친구 관계를 전부 찾으면 된다.

    위 방식이 그런 방식
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    string *s = new string[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int **m = new int *[n];
    for (int i = 0; i < n; i++)
    {
        m[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == 'Y')
                m[i][j] = 1;
            else
                m[i][j] = 999;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                m[i][j] = min(m[i][j], m[i][k] + m[k][j]);
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] < 3)
                count++;
        }
        if (max < count)
            max = count;
    }

    cout << max;

    delete[] s;
    for (int i = 0; i < n; i++)
        delete[] m[i];
    delete[] m;
}

// 풀이 2. 플로이드 워셜 알고리즘을 이용한 풀이

/*

    플로이드 워셜 알고리즘은 다익스트라 알고리즘같은 최단거리 알고리즘의 일종인데

    모든 노드로부터 다른 모든 노드로 가는 최단거리를 구하는 것이다 가령,

    a <-> b
      (3)
    a <-> c
      (6)
    b -> c
      (1)

    라고 a,b,c 세 노드간의 거리를 정의 했을때 
    a->b로 가는 가장 짧은 거리, b->c로 가는 가장 짧은 거리, a->c로 가는 가장 짧은 거리 모두를
    구하는 것이다.


    사용하는 자료구조는 2차원 배열로, 가령 0행 2열은 0->2로 가는 가장 짧은 거리를 의미한다.
    나는 이 거리를 D(0,2)라고 정의할 것이다.
    이 거리 D(a,b)는 다음과 같은 점화식으로 정의 된다.

    D(a,b) = min(D(a,b), D(a,k) + D(k,b))

    즉, 두 거리를 비교해보는 건데

    1. 그냥 직방으로 a->b로 이동 하는 거리
    2. k를 거쳐서 a->k로 이동하는 최단 거리와, k->b로 이동하는 최단 거리의 합

    직관적으로 봐도 맞는 말이다. 모든 거쳐야 할 k를 다 찾아보면 
    최종적으로 a->b로 가는 최단거리를 구할 수 있을 것이다.

    이 문제에서는 2-친구 관계를 전부 찾아야 하므로, 플로이드 워셜 알고리즘을 사용하면 되는 것이다.


*/


/*
    성능 비교

    우선 첫번째 DFS는 최상의 경우 n^2logn, 최악의 경우 n^3이 걸릴 것이다.
    그래도 인풋 케이스에 따라서 성능이 더 나아질 여지가 있다니 다행이다.

    그런데 플로이드 워셜 알고리즘은 고정적으로 항상 n^3이다.

    그 이유는 항상 2차원 배열 모든 원소를 업데이트 해야하기 때문에 n^2번은 기본적으로 둘러봐야 하는데,
    이 둘러보는 행위를 가능한 모든 k에 대해 거쳐봐야 하므로 n^3이 되는 것이다.

    그래서 사실 n값이 적당하거나 작다면 그냥 플루이드를 써도 되긴 하지만
    조금만 더 커져버리면 플루이드 알고리즘이 잡아먹는 성능은 어마어마 해지는데다가,
    다익스트라 알고리즘과 비교하면 상당히 정적인 최단 거리 알고리즘이므로 
    쓰임새를 잘 알고 상황에 맞게 써야 할 것이다.

*/