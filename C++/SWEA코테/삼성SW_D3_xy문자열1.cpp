// SWEA x,y문자열1
// D3
// 30분
// 그리디, 문자열, 역추적

#include <iostream>
#include <deque>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++)
    {
        string s, e;
        cin >> s >> e;
        deque<char> dq;

        for (int j = 0; j < e.length(); j++)
        {
            dq.push_back(e[i]);
        }

        bool flag = true;
        while (dq.size() > s.length())
        {
            if (flag)
            {
                char c = dq.back();
                if (c == 'Y')
                    flag = false;
                dq.pop_back();
            }
            else
            {
                char c = dq.front();
                if (c == 'Y')
                    flag = true;
                dq.pop_front();
            }
        }

        string s2 = "";
        while (!dq.empty())
        {
            if (flag)
            {
                s2 += dq.front();
                dq.pop_front();
            }
            else
            {
                s2 += dq.back();
                dq.pop_back();
            }
        }

        if (s2 == s)
        {
            cout << "#" << i << " Yes\n";
        }
        else
        {
            cout << "#" << i << " No\n";
        }
    }
}