// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3외로운문자
// 24/05/05
// 15분

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        vector<int> v(26);

        for (auto i : s)
        {
            v[i - 'a'] = (v[i - 'a'] + 1) % 2;
        }

        string g = "Good";
        cout << "#" << test_case << " ";
        for (int i = 0; i < 26; i++)
        {
            if (v[i] > 0)
            {
                cout << (char)(i + 'a');
                g = "";
            }
        }
        cout << g << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//26개의 알파벳을 벡터 인덱스 숫자로 대응시켜서
//문자에 해당하는 인덱스 번지로 count시켜주고
//2개씩 짝지어질때마다 0으로 되돌린다
//이후 count sort기법으로 배열 0번~25번을 전부 탐색하여
//1이 나올때마다 그에 해당하는 문자를 역연산해서 출력시켜주면 된다.