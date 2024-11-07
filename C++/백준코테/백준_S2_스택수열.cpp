// 문제번호 : 1874번
// 스택수열
// 푼 시간 : 20분
// 알고리즘 분류 : 스택

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    stack<int> stk;
    string ans = "";
    int max = 0;
    int k;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        for (int j = max + 1; j <= k; j++)
        {
            stk.push(j);
            ans += "+\n";
        }
        if (max < k)
            max = k;

        if (stk.top() == k)
        {
            stk.pop();
            ans += "-\n";
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << ans;
}
