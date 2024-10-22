// 문제번호 : 10828번
// 스택
// 푼 시간 : 15분
// 알고리즘 분류 : 구현, 스택

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    vector<int> v({-1});
    cin >> n;
    v.reserve(n);
    for (int i = 0; i < n; i++)
    {
        int val = -1;
        string cmd;
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> val;
            v.push_back(val);
        }
        else if (cmd == "pop")
        {
            int endval = *(v.end() - 1);
            cout << endval << endl;
            if (endval != -1)
                v.erase(v.end() - 1);
        }
        else if (cmd == "top")
        {
            cout << *(v.end() - 1) << endl;
        }
        else if (cmd == "size")
        {
            cout << v.size() - 1 << endl;
        }
        else if (cmd == "empty")
        {
            int flag = v.size() == 1 ? 1 : 0;
            cout << flag << endl;
        }
    }
}

// iterator도 포인터 처럼 사용 가능하다.
//  그리고 v.end()에는 원소가 담겨있지 않으니 주의! 실질적으로 마지막 원소는 v.end()-1에 있다.