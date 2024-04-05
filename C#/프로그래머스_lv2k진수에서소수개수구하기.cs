//https://school.programmers.co.kr/learn/courses/30/lessons/92335#
//프로그래머스_lv2k진수에서소수개수구하기
//2024.04.05
//20분

using System;
using System.Linq;
public class 프로그래머스_lv2k진수에서소수개수구하기 {
    string changeNum(int n, int k){
        string s = "";
        while(n>=k){
            int a = n % k;
            n = n / k;
            s+=a;
        }
        s+=n;
        return new string(s.Reverse().ToArray());
    }
    
    bool isPrime(long k){
        if(k<=1) return false;
        for(long i=2; i*i<=k; i++){
            if(k%i==0) return false;
        }
        return true;
    }
    
    
    public int solution(int n, int k) {
        int answer = 0;
    
        string s = changeNum(n,k);
        string ss = "";
        
        foreach(var c in s){
            if(c == '0' && ss!=""){
                long num = long.Parse(ss);
                if(isPrime(num))   answer++;
                ss ="";
            }
            else ss+=c;
        }
        if(ss!=""){
             long num2 = long.Parse(ss);
             if(isPrime(num2)) answer++;
        }
        
        return answer;
    }
}

//이 문제는 소수구하기 + n진수 구하기 + 문자열 처리
//세 개가 결합된 혼종 문제다.
//O(sqrt(n))의 소수 구하기, O(log(n))의 n진수 구하기
//이거 두개 할 줄 알면 문자열 처리 부분은 구현 파트니까 그다지 어렵진 않음
 