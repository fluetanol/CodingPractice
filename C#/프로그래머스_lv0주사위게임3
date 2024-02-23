//https://school.programmers.co.kr/learn/courses/30/lessons/120866
//프로그래머스_lv0주사위게임3
//2024-02-23
//소요시간 25분

using System;
using System.Collections.Generic;

public class 프로그래머스_lv0주사위게임3{
    public int solution(int a, int b, int c, int d) {
        int answer = 0;
        int Mode = 0;
        var list = new List<int>(){a,b,c,d};
        var dictionary = new Dictionary<int, int>();
        
        int min = 999;
        foreach(var i in list){
            if(!dictionary.ContainsKey(i)) {
                dictionary[i] = 1;
                if(min>i)
                    min = i;
            }
            else {
                dictionary[i] +=1;
                Mode+=1;
                if(dictionary[i] > 2) Mode+=1;
            }
        }
        

        int p = 0;
        int q = 0;
        int r = 0;
        foreach(var i in dictionary.Keys){ 
            if(dictionary[i] == 1 && q == 0)  q = i;    
            else if (dictionary[i] == 1 && r == 0)  r = i; 
            else if(dictionary[i] == 2 && p == 0)  p = i; 
            else if(dictionary[i] == 2 && q == 0) q = i;
            else if(dictionary[i] == 3 || dictionary[i] == 4) p = i;
        }
        
        switch(Mode){
            case 0:
                answer = min;
                break;
            case 1:
                answer = q * r;
                break;
            case 2:
                answer = (p + q) * Math.Abs(p-q);
                break;
            case 3:
                answer = (int)Math.Pow((10 * p + q), 2);
                break;
            case 5:
                answer = 1111 * p;
                break;
            default:
                break;
        }

        return answer;
    }
}

//lv0주제에 짜증난 문제
//중복되어 나온 숫자의 케이스에 따라 Mode를 두어 나누었다.
//중복된 숫자가 많을수록 mode값이 증가하고, 또한 두 개 이상 같은 숫자가 나온 경우에
//나머지 두 숫자가 서로 다르거나 같은 경우로 나뉘기 때문에 
//같은 숫자의 갯수가 2 이상인 경우 추가 1의 가중치가 붙도록 설계 했다.

//그리하면 mode 0은 모두 다른 경우, mode 1은 하나만 같고 나머지 둘은 서로 다른 경우
//mode 2는 두개 두개가 짝지어 같은 경우, mode 3은 세개가 같고 하나가 다른 경우,
//mode 5는 네개가 모두 같은 경우가 되고 이를 switch case로 조건을 나누어 표현 했다.

//한편 p,q,r값은 어쩔 수 없이 조건문을 전부 나누어서 표현함
//근데 이거보다 더 좋은 방법이 분명 있을거같음
//내가 푼 방식은 순수 직관적인 구현에 초점을 둔 방식이여서 (데이터 갯수가 작아서 시간소모를 무시해도 됨)
//최적화에는 별 신경 쓰지 않았음.
//그런데 다른 사람이 푼것도 보니까 일일히 케이스 나누어서 풀어야 하는 문제가 맞는듯 하다.
//문제 자체가 어렵진 않은데 오히려 최적화에 목숨 거는 개발자면 불편했을 문제인듯 