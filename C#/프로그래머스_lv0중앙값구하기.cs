//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/02/18
using System;
public class 프로그래머스_lv0중앙값구하기
{
    public int solution(int[] array)
    {
        int answer = 0;
        Array.Sort(array);
        int middle = array.Length;
        answer = array[middle / 2];
        return answer;
    }
}

//sort에 관한 문제가 아니여서 기본제공 sort함수를 쓰는게 정신건강에 이로움