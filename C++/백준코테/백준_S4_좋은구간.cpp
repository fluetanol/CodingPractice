// 문제번호 : 1059번
// 좋은 구간
// 푼 시간 : 10분
// 알고리즘 분류 : 브루트 포스, 수학, 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l, n;
    cin >> l;
    vector<int> v(l);
    for (int i = 0; i < l; i++)
        cin >> v[i];
    cin >> n;

    sort(v.begin(), v.end());

    int k;
    for (k = 0; k < l; k++)
    {
        if (v[k] > n)
            break;
        else if (v[k] == n)
        {
            k = -1;
            break;
        }
    }

    if (k == -1)
        cout << 0;
    else
    {
        int count = 0;
        int s = k - 1 >= 0 ? v[k - 1] : 1;
        int e = v[k];
        for (int i = s + 1; i <= n; i++)
        {
            for (int j = n; j < e; j++)
            {
                if (i != j)
                {
                    cout << i << " " << j << endl;
                    count++;
                }
            }
        }
        cout << count;
    }

    return 0;
}


//구간 A, B는 A<B여야 하는데 주어지는 집합 S는 꼭 오름차순 정렬이 되있으라는 보장이 없어서 SORT를 꼭 쓸것.
//어차피 SORT가 주된 문제는 아니라 sort()내장 함수 쓰면 됨.


// 그 외엔 그냥 주어진 조건대로 가능한 "좋은 구간"이 몇개인지 세면 됨.