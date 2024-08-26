// 문제번호 : 1060번
// 좋은수
// 푼 시간 : 이틀...
// 알고리즘 분류 : 수학, 우선순위 큐, 정렬

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void input(vector<vector<long long>> &v, int &l, int &n)
{
    cin >> l;
    for (int i = 0; i < v.size(); i++)
        v[i].resize(l + 1);

    // 0행: 집합 S
    for (int i = 1; i < l + 1; i++)
        cin >> v[0][i];
    sort(v[0].begin(), v[0].end());

    // 1행: 좋은 수
    for (int i = 0; i < l + 1; i++)
        v[1][i] = v[0][i];

    // 2행: 좋은 구간의 수 (0으로 초기화)

    // 3행: 다음 숫자 간의 간격
    // 4행: 다음 좋은 구간의 합
    for (int i = 0; i < l; i++)
    {
        v[3][i] = v[0][i + 1] - v[0][i] - 1;
        v[4][i] = v[3][i] - 1;
    }

    v[3][l] = numeric_limits<long long>::max();
    v[4][l] = numeric_limits<long long>::max();

    // 5행 플래그
    for (int i = 0; i < l + 1; i++)
    {
        v[5][i] = 1;
    }

    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, n;
    vector<vector<long long>> v(6);
    input(v, l, n);

    int count = 0;
    while (count < n)
    {
        long long min = numeric_limits<long long>::max();
        int minidx = -1;

        for (int i = 0; i < v[0].size(); i++)
        {
            if (min > v[2][i] && v[3][i] > -1)
            {
                min = v[2][i];
                minidx = i;
            }
        }

        if (minidx == -1)
            break;

        //  0보다 큰 정수인 경우 -> 정상 출력 처리
        if (v[1][minidx] > 0)
        {
            cout << v[1][minidx] << " ";
            count++;
        }

        // 더하는 상황
        if (v[5][minidx] > 0)
        {
            v[1][minidx] = v[0][minidx] + v[5][minidx];
            v[2][minidx] += v[4][minidx];
            if (v[5][minidx] > 2)
                v[2][minidx] -= (v[5][minidx] - 2);
        }

        // 빼는 상황
        else
        {
            v[1][minidx] = v[0][minidx + 1] + v[5][minidx];
            v[4][minidx]--;
            v[5][minidx]--;
        }

        v[3][minidx]--;
        v[5][minidx] *= -1;
    }

    int rest = v[0][v[0].size() - 1] + 1;
    for (int i = 0; i < n - count; i++)
    {
        cout << rest++ << " ";
    }
}
