//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/03/17

using System;

public class 공배수 {
    public int solution(int number, int n, int m) {
        int answer = 0;
        if(number%n==0 && number%m==0) answer = 1;
        return answer;
    }
}