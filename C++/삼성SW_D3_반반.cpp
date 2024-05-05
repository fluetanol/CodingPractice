// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3반반
// 24/05/05
//

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        unordered_map<char, int> m;
        cin >> s;

        for (auto i : s)
            if (m.find(i) == m.end())
                m.insert({i, 1});

        if (m.size() == 2)
            cout << "#" + to_string(test_case) + " " << "Yes" << endl;
        else
            cout << "#" + to_string(test_case) + " " << "No" << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//hashmap연습문제
//d3라 보긴 어렵고 쉬운 d2문제에 가까웠다.