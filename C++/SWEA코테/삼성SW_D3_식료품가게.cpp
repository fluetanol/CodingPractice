// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3식료품가게
// 24/05/05
// 40분


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<int> v(n * 2);
        unordered_map<int, int> s;
        for (int i = 0; i < n * 2; i++)
        {
            cin >> v[i];
            if (s.find(v[i]) == s.end())
                s.insert({v[i], 1});
            else
                s[v[i]] += 1;
        }

        cout << "#" << test_case << " ";
        for (int i = 0; i < n * 2; i++)
        {
            int d = v[i] * (100.0 / 75.0);
            if (s[v[i]] <= 0)
                continue;
            else if (s.find(d) != s.end() && s[d] > 0)
            {
                s[v[i]]--;
                s[d]--;
                cout << v[i] << " ";
            }
        }
        cout << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//헷갈리는 문제...
//우선 맨 아래에 있는 가격은 반드시 할인 가격이라는 점에서 시작해야한다.
//즉, 할인 가격에서 100/75를 곱해 정상 가격을 찾아나가며 
//소거 해가는 방식으로 풀어야 한다는 것
//처음엔 반대로 풀려고 했다가 좀 낭패를 봐버렸다.

// 그리고,      
// v[i] * (100.0 / 75.0);
//이 연산의 경우 float로 값을 받으면 부동소수점 문제로
//해쉬셋의 find함수가 오동작 할 수 있으니
//반드시 int로 받아서 처리해두도록 한다
//어차피 문제에선 무조건 int가 될 수 밖에 없는 케이스만 주어지므로
//이렇게 풀어도 상관없음

//또한~!!  100/75연산은 일반 정수 나눗셈 연산이여서
//소수점 아래자리가 싹다 버림되어서 1.333...이 아닌 1로 연산되니까
//이 점도 참고하여 100f나 100.0처럼 실수화 시켜서 연산시켜야
//제대로된 결과값이 나온다는 상식을 알아두자.