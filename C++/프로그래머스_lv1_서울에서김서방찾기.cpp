// https://school.programmers.co.kr/learn/courses/30/lessons/12919
// 프로그래머스_lv1서울에서김서방찾기
// 24/06/14
// 1분

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul)
{
    string answer = "";

    for (int i = 0; i < seoul.size(); i++)
    {
        if (seoul[i] == "Kim")
        {
            answer = "김서방은 " + to_string(i) + "에 있다";
            break;
        }
    }
    return answer;
}