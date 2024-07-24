// 문제번호 : 1027번
// 고층건물
// 푼 시간 : 1시간 반
// 알고리즘 분류 : 완전탐색

#include <iostream>
#include <vector>
using namespace std;

int intersectionCount(double pivot, double pos, vector<int> &v)
{
    double dx_dy = (v[pivot] - v[pos]) / (pivot - pos);
    double b = v[pivot] - dx_dy * pivot;

    bool count = 1;

    int s = pos > pivot ? pivot : pos;
    int e = pos > pivot ? pos : pivot;

    for (int x = s + 1; x < e; x++)
    {
        double y = dx_dy * x + b;
        if (v[x] >= y)
        {
            count = 0;
            break;
        }
    }

    return count;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int countmax = 0;
    for (int pivot = 0; pivot < n; pivot++)
    {
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (i != pivot)
                count += intersectionCount(pivot, i, v);
        }
        countmax = count > countmax ? count : countmax;
    }
    cout << countmax;
}

//완전 탐색 문제
//결론부터 말하면 두 건물 간 가려지는 건물이 얼마나 있는지 파악하는 문제다.

//고층 건물 하나를 피벗으로 잡고 양 옆 건물과의 기울기를 구하고
//그 기울기로 피벗과 다른 건물 사이에 있는 건물들을 검사한다.

//예를들어

// 1 7 10 8 1
// 이렇게 있을때 10을 피벗으로 잡는다면
// 우측 1은 7에 의해 가려지고
// 좌측 1은 8에 의해 가려지므로
// 10에서 볼 수 있는 총 건물 갯수는 7,8 두개이다.

// 이런식으로 모든 건물을 피벗으로 잡아서 max를 도출하면 됨.
// 어차피 완전탐색이라 최적화 할 구멍은 딱히 없고 리스트 크기는 50이 최대여서 시간내에 충분히 돌아감




