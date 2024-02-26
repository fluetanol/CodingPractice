//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/02/26

using System;

public class 프로그래머스_lv0다음에올숫자
{
    public int solution(int[] common)
    {
        int answer = 0;

        int a1 = common[0];
        int a2 = common[1];
        int a3 = common[2];

        if (a2 - a1 == a3 - a2) answer = common[common.Length - 1] + (a2 - a1);
        else answer = common[common.Length - 1] * (a2 / a1);

        return answer;
    }
}