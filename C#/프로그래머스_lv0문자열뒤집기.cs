//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음 
// 2024/02/18
using System;
using System.Linq;

public class 프로그래머스_lv0문자열뒤집기
{
    public string solution(string my_string)
    {
        string answer = "";

        //method 1  (should using System.Linq)
        answer = new string(my_string.Reverse().ToArray());

        //method 2  (should using System.Linq)
        char[] chararr = my_string.ToArray();
        Array.Reverse(chararr);
        answer = new string(chararr);

        //method3
        answer = "";
        for (int i = my_string.Length - 1; i >= 0; i--) answer += my_string[i];

        return answer;
    }
}

//c#에서 문자열 뒤집는 저 세가지 방법을 전부 익혀두도록 하자...
