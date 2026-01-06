#include <iostream>

using namespace std;

string arr[30];

int palindrome(string s, int l, int r , int palin) {
    if (palin == 2) return palin;


    while (r >= l) {
        if (s[r] != s[l]) {
            //왼쪽 것을 지워야 할 지 오른쪽 것을 지워야 할 지에 대한 선택
            //부분 문제라고 생각하고 재귀를 돌린다.
            int palin1 = palindrome(s, l + 1, r, palin + 1);
            int palin2 = palindrome(s, l , r - 1, palin + 1);
            
            if (palin1 == 1 || palin2 == 1) return 1;
            else return 2;
        }

        ++l;
        --r;  
    }
    
    return palin;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
 
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> arr[i];
    }

    for (int i = 0; i < t; ++i) {
        cout << palindrome(arr[i], 0, arr[i].length()- 1 , 0) << "\n";
    }

}

