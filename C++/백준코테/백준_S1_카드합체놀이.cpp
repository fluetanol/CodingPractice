// 문제번호 : 15903번
// 카드합체놀이
// 푼 시간 : 40분
// 알고리즘 분류 : 그리디 알고리즘, 우선순위 큐

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<long long> v;
    v.reserve(1000);
    for (int i = 0; i < n; i++)
    {
        long long n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int count = 0;

    while (count < m)
    {
        long long sum = v[0] + v[1];
        int i;
        for (i = 1; i < v.size(); i++)
        {
            if (sum < v[i])
            {
                v.insert(v.begin() + i, sum);
                v.insert(v.begin() + i, sum);
                break;
            }
        }
        if (i == v.size())
        {
            v.push_back(sum);
            v.push_back(sum);
        }
        v.erase(v.begin());
        v.erase(v.begin());
        count++;
    }

    long long sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
    }
    cout << sum << endl;
}

//우선순위큐를 따로 두진 않았고, 대신 sum된 값이 어느 위치에 들어갈지 비교하고 삽입했다.
/*
    참고로 가장 작은 합을 도출해야 하므로, 
    계속 해서 가장 작은 두 수를 더해서 더한 두 값이 최솟값이 되는 경우만을 골라야 한다.
    그래서 오름차순 정렬을 활용했다.
*/