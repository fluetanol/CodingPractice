// 문제번호 : 1015번
// 수열정렬
// 푼 시간 : 20분
// 알고리즘 분류 : 정렬

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning(disable : 4996)

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> p(n);

    for (int i = 0; i < n; i++)
    {
        int min = 9999;
        int minidx = 0;
        for (int j = 0; j < a.size(); j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                minidx = j;
            }
        }
        p[minidx] = i;
        a[minidx] = 9999;
    }

    for (auto k : p)
        cout << k << " ";

    return 0;
}


/*
    그냥 모든 원소를 n번 순회하면서 다음 최솟값을 계속 찾아나가는 방식으로 풀었다.
    O(n^2);

*/

//다른 풀이

int a[60];
int p[60];
int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (a[i] >= a[j])
                p[i]++;
        }
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                p[i]++;
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", p[i]);
    }
    printf("\n");
}

/*
    최솟값을 구할 것 없이 각 원소마다 자기보다 작은 원소의 갯수를 구하는 방식

    a[i]를 기준으로 자기보다 크다면 p[i]를 증가시키는데,
    만약 가장 큰 놈이라면 n-1이 될 것이고, 가장 작은 놈은 증가될 일이 없어서 0일 것이다.
    최솟값을 구하는 방식보다 더 일반화를 잘 시킨 방식.
    그래도 여전히 O(n^2)임


*/