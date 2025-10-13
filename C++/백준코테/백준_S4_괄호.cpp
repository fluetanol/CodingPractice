#include <iostream>
#include <stack>
using namespace std;



int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        stack<int> stk;
        bool flag = false;
        for (int j = 0; j < s.length(); ++j) {
            if (s[j] == '(') {
                stk.push(s[j]);
            }
            else {
                if(stk.size() > 0)
                    stk.pop();
                else {
                    flag = true;
                    break;
                }
            }
        }
        
        if (stk.empty() && !flag) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    
    }

}


//stack을 이용한 문제
//괄호 매칭을 확인하면 되는데
//만약 마지막에 매칭이 안되어 남은 게 하나라도 있으면
//제대로 된 괄호 문자열이 아닌 것이다.
//한가지 예외라면 이미 열린 괄호가 전부 매칭 된 상태에서
//닫는 괄호가 먼저 나오는 경우, 더 이상 pop을 할 수 없으므로
//즉시 끝내면 됨
