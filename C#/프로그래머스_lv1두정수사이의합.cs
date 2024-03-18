//https://school.programmers.co.kr/learn/courses/30/lessons/12912
//프로그래머스_lv1두정수사이의합
//2024.03.17
//3분

public class 두정수사이의합 {
    public long solution(int a, int b) {
        long answer = 0;
        if(b<a){
            int temp = b;
            b= a;
            a= temp;
        }
        for(int i=a; i<=b; i++) answer += i;
        
        return answer;
    }
}