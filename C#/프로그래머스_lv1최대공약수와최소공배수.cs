//https://school.programmers.co.kr/learn/courses/30/lessons/12940
//프로그래머스lv1최대공약수와최소공배수
//2024.02.29
//소요시간10분

using System;
public class 프로그래머스lv1최대공약수와최소공배수 {
    public int[] solution(int n, int m) {
        int[] answer = new int[2];
        int nm = n*m;
        if(n>m){
            int temp = m;
            m = n;
            n = temp;
        }
        
        while(n != 0){
            int k =  m % n;
            if(k==0) break;
            m = n;
            n = k;
        }
        answer[0] = n;
        answer[1] = nm/n;
        return answer;
    }
}

//최대공약수, 최소공배수 알고리즘을 공부할 수 있는 좋은 문제

//GCD라는 유클리드 호제법을 쓴다

//1. 최대공약수
//두 수 N, M이고 N>M일때 N, M의 나머지 K가 M을 나누어 떨어지게 하는지 확인한다.
//나누어 떨어지면 그 K가 최대공약수.
//예를 들어 30 24이라면
//30%24 = 6, 
//이 때 K=6, M=24라면 24%6 = 0 이므로 6이 최대공약수.

//2. 최소공배수
//다음같은 수학적 성질을 이용해주면 된다.
//두 수 N, M이 있을때
//최소공배수 = N * M / 최대공약수