// 문제번호 : 1037번
// 약수
// 푼 시간 : 10분
// 알고리즘 분류 : 수학

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>
#pragma warning(disable : 4996)
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k;
    cin >> k;
    int min = 999999999;
    int max = -1;

    for (int i = 0; i < k; i++)
    {
        int a;
        cin >> a;
        if (a > max)
            max = a;
        if (a < min)
            min = a;
    }

    int n = max * min;
    cout << n;
}