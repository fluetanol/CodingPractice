// https://school.programmers.co.kr/learn/courses/30/lessons/12915
// 프로그래머스_lv1문자열내맘대로정렬하기
// 24/06/15
// 15분

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num = 0;

bool compare(string a, string b)
{
    if (a[num] != b[num])
        return a[num] < b[num];
    else
    {
        int i = 0, j = 0;
        while (true)
        {
            if (a.size() == i || b.size() == j)
                return a.size() < b.size();
            else if (a[i] != b[j])
                return a[i] < b[j];
            i++;
            j++;
        }
    }
}

vector<string> solution(vector<string> strings, int n)
{
    vector<string> answer;
    num = n;
    sort(strings.begin(), strings.end(), compare);
    answer = strings;

    return answer;
}

//lv1주제에 좀 까다로웠던 문제
//이 문제에서 생각해야 할 조건은 
/*
    1. 인덱스 n의 문자가 다른 경우, 해당 문자를 기준으로 그냥 정렬
    2. 인덱스 n의 문자가 같은 경우, 그냥 사전 순 정렬

    예를 들어 1의 경우
    abcd와 afdp가 있다고 할때, n=1이라면
    b와 f를 비교해서 b가 더 작으므로 abcd가 먼저 오게 된다.

    2의 경우
    abcd와 abce가 있다고 할때, n=1이라면
    두 문자열의 n번째 문자가 같으므로 사전 순으로 정렬한다.
    따라서 abcd가 먼저 오게 된다.

    저 두가지 경우를 생각해서 compare함수를 구현했다.

    1은 단순히 num번째 인덱스의 문자를 비교해서 리턴하면 되는건데
    2의 경우에는 문자열의 길이를 넘어가면 안되기 때문에 while문을 돌려서
    문자열의 길이를 넘어가면 그 문자열이 더 작다고 판단하도록 했다.
    그 전에 이미 다른 문자가 나왔다면 두 문자를 비교해서 compare함수를 리턴시키면 됨.

    참고로 num 전역변수는 compare에 전달 가능한 인자가 2개 뿐이라서
    전역변수로 선언해서 사용함.
    


*/