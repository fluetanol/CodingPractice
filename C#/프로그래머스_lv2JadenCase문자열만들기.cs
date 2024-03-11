//https://school.programmers.co.kr/learn/courses/30/lessons/12951
//프로그래머스_lv2JadenCase문자열만들기
//2024.03.11
//20분

using System;
using System.Linq;
public class 프로그래머스_lv2JadenCase문자열만들기
{
    public string solution(string s)
    {
        string answer = "";
        var splits = s.Split(" ");
        foreach (var i in splits)
        {
            if (i != "")
            {
                string temp = i.ToLower();
                if (!int.TryParse(i[0].ToString(), out int strr)) temp = temp.Remove(0, 1).Insert(0, char.ToUpper(i[0]).ToString());
                answer += (temp + " ");
            }
            else answer += " ";
        }
        answer = answer.Remove(answer.Length - 1, 1);
        return answer;
    }
}

// 공백문자가 연속으로 나온다는 조건이 쫄리긴 하나...
// split이 연속 공백문자를 어떻게 처리하는지 보면 풀기 쉬웠다

// 1. split(" ")이 연속된 공백을 만나게 될 경우 그냥 빈문자 ""를 반환한다.
// 이 때는 별다른 처리 없이 공백만 더해준다.

// 2. 빈문자가 아닌 유의미한 문자인 경우, 앞글자 str[0]이 숫자인지 아닌지 판별한다.
//이를 위해 int를 tryparse를 해보면 된다 (일반 문자라면 tryeparse를 해도 false가 나온다.)

//3. parse가 안된 문자라면 앞글자가 숫자가 아니므로 대문자 변환을 해주는 작업을 한다

//4. 2~3으로 인해 바뀐 문자열을 더해주고 공백을 붙힌다.

//5. 최종적으로 마지막 문자에 쓸데없이 붙은 공백 하나를 지워준다. (answer = answer.Remove(answer.Length - 1, 1);)

