//https://school.programmers.co.kr/learn/courses/30/lessons/12939
//프로그래머스_lv2최댓값과최솟값
//2024.03.11
//5분
using System;
using System.Linq;
public class 프로그래머스_lv2최댓값과최솟값
{
    public string solution(string s)
    {
        string answer = "";
        int min = 99999999;
        int max = -99999999;

        foreach (var i in s.Split(" "))
        {
            int num = int.Parse(i);
            if (num < min) min = num;
            if (num > max) max = num;
        }
        answer = min + " " + max;

        return answer;
    }
}
//lv2치고 너무 쉬운 문제긴 했는데, 사실 이 풀이는 도박성이 짙은 문제다
//우선 min값이 99999999보다 큰 값이 널린 경우, max값이 -99999999 보다 작은 값으로 덮혀진 경우,
//그러면 저 알고리즘은 틀린다.
//특히 이 문제는 어느 범위까지의 숫자가 나올지 명시가 안되었기 때문에(string이여서ㅋㅋ)
//극단적인 input에 따라 틀릴수도 있는 예시이다.

//가장 명확한 방법은 내장되어있는 min, max함수를 쓰거나, array를 sort해서 양극단 번지에 있는
//숫자값을 가져오는 것이다.


public class 프로그래머스_lv2최댓값과최솟값2
{
    public string solution(string s)
    {
        string answer = "";
        int[] temp = s.Split(' ').Select(int.Parse).ToArray();
        answer = temp.Min().ToString() + " " + temp.Max().ToString();
        return answer;
    }
}
//타인이 풀었던 가장 깔롱쌈뽕했던 풀이