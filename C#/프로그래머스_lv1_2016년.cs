//https://school.programmers.co.kr/learn/courses/30/lessons/12901
//프로그래머스_lv12016년
//2024.02.26
//15분
using System;

public class 프로그래머스_lv12016년
{
    public string solution(int a, int b)
    {


        string answer = "";
        string[] dayday = new string[] { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

        int day = -1;
        for (int i = 1; i <= a; i++)
        {
            if (i == a) day += b;
            else if (i == 2) day += 29;
            else if ((i % 2 == 1 && i <= 7) || (i % 2 == 0 && i > 6)) day += 31;
            else if ((i % 2 == 1 && i > 7) || (i % 2 == 0 && i <= 6)) day += 30;
        }
        answer = dayday[day % 7];
        return answer;
    }
}

//간단하게 일수로 바꾸고 이를 7로 나눈 나머지에 해당되는 요일을 뽑는 방식
//2016년은 금요일부터 시작하므로, 금요일을 시작점으로 주기를 만들어주면 된다.
//조건문 처리하는 귀찮음 빼면 쉬워씀