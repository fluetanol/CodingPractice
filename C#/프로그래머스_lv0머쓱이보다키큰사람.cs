//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/02/18
using System;
public class 프로그래머스_lv0머쓱이보다키큰사람
{
    public int solution(int[] array, int height)
    {
        int answer = 0;
        foreach (var i in array) answer = i > height ? answer + 1 : answer;
        return answer;
    }
}

//원래대로라면 그냥 if(i >height)를 이용하는게 가장 좋으나, 
//람다식 연습도 해보는 것도 좋을 거 같아서 람다식 써봄

