//https://school.programmers.co.kr/learn/courses/30/lessons/12930
//프로그래머스lv1이상한문자만들기
//2024.02.19
//소요시간10분

using System;
public class 프로그래머스lv1이상한문자만들기
{
    public string solution(string s)
    {
        string answer = "";
        int idx = 0;

        foreach (var i in s)
        {
            string str = i.ToString();
            if (str == " ")
            {
                answer += " ";
                idx = 0;
                continue;
            }
            if (idx % 2 == 0) answer += str.ToUpper();
            else if (idx % 2 == 1) answer += str.ToLower();
            idx += 1;
        }
        return answer;
    }
}

//이 방법 말고도 tostring을 쓰지 않고 char형인 i의 아스키코드값을 직접 조절하여 푸는 방법도 있고
//문자를 split하여 각 단어별로 대소문자를 조절하는 방법도 있다.