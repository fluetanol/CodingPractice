// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d4염라대왕의이름정렬
// 24/04/28
// 40분

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool stringDictionaryCompare(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] < b[i])
                return true;
            else if (a[i] > b[i])
                return false;
        }
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    string answer = "";
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        string *names = new string[n];
        for (int i = 0; i < n; i++)
        {
            cin >> names[i];
        }
        sort(names, names + n, stringDictionaryCompare);
        answer += "#" + to_string(test_case) + "\n";
        string bs = "";

        for (int i = 0; i < n; i++)
        {
            if (bs != names[i])
                answer += names[i] + "\n";
            bs = names[i];
        }
    }
    cout << answer;
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

// 일반적인 sort알고리즘을 직접 구현하려하면 좀 까다롭기 때문에
// stl sort를 이용해서 두 원소간 자리를 바꾸는 기준을 함수로 만드는 것에만 초점을 두는게 편하다.
// 함수의 조건문은 두 가지로 나뉜다.

// 1. 문자열 a와 b의 길이가 다른 경우
// 더 큰 쪽이 뒤로 가도록 자리를 바꾸면 된다

// 2. 문자열 a와 b의 길이가 같은 경우
// 문자열의 문자를 하나씩 1대1 비교하면서 알파벳 아스키코드값이 더 큰 쪽이
// 뒤로 가도록 자리를 바꾸면 된다

//위 두개의 조건에 맞춰서 하나의 함수로 구현하면 끝난다.
//처음에는 길이가 같은 것 끼리 묶는 정렬 -> 문자열간 사전순 정렬
//이렇게 나눠서 정렬을 했는데
//그러다 보니까 이중 정렬을 하면서 문제가 생겼던것 같아서
//한번의 정렬안에 사전순 정렬과 길이 순 정렬을 하도록 설계 하는 방향으로 바꾸니 풀렸다

//여러모로 정렬의 부하가 큰 편이라서 출력 또한 한번에 묶어서 해야 했다는 점이 까다로운 것.
//만약 최적화를 해야한다면 hash_set이라도 써서 중복 단어를 제거하고 
//그 안에서 정렬 하는 방식을 써야 할 듯 하다.