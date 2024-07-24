// 문제번호 : 1026번
// 보물
// 푼 시간 : 0916
// 알고리즘 분류 : 카운트정렬, 그리디 알고리즘

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

    vector<int> a(101);
    vector<int> b(101);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[k]++;
    }
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        b[k]++;
    }

    int sum = 0;
    int apivot = 0;
    int bpivot = 100;

    while (n > 0)
    {
        if (a[apivot] > 0 && b[bpivot] > 0)
        {
            sum += apivot * bpivot;
            a[apivot]--;
            b[bpivot]--;
            n--;
        }
        else if (a[apivot] == 0)
            apivot++;
        else if (b[bpivot] == 0)
            bpivot--;
    }

    cout << sum;
}

//카운트 정렬 + 그리디 문제

/*
    두 수의 곱이 최소가 되려면 가장 큰 수와 가장 작은 수를 곱하면 된다.
    각 곱이 계속 최소의 경우가 합해지면, 당연히 전체 합도 최소일 것이다.

    0 0 7
    1 5 6

    이 있다고 치면, 당연히 큰 숫자들 6,5가 0과 만나서 0으로 제거되고
    7,1이 곱해져서 7이 나올 것이다.

    근데 이럴려면 한쪽은 오름차순 정렬, 다른 한 쪽은 내림차순 정렬을 해야하는데
    요즘 stl이 잘 나와있어서 sort를 써도 되지만
    난 그냥 카운트 정렬을 써서 풀기로 했다.
    이유인 즉슨 중복 원소가 인풋 데이터로 가능해서 카운트 정렬이 더 큰 강점을 발휘할거라 생각했음

    그 외에는 그냥 코드 읽으면서 이해해라
    어렵진 않음
*/