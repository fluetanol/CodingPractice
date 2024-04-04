//https://school.programmers.co.kr/learn/courses/30/lessons/133499?language=csharp
//프로그래머스lv1옹알이2
//2024.04.04
//30분


using System;
using System.Collections.Generic;

public class Solution {
    bool babble(string w){
        string s = "";
        string befores = "";
        bool isBabble = false;
        int count = 0;
        foreach(var k in w){
            s+=k;
            count++;
            if(s=="ye" || s=="ma" || s == "woo" || s=="aya") {
                if(befores == s) {
                    isBabble = false;
                    break;
                }
                isBabble = true;
                befores = s;
                s = "";
            }
            else if(s.Length>=3 || (count == w.Length && s.Length!=0)){
                isBabble = false;
                break;
            }
        }    
        return isBabble;
    }
    
    public int solution(string[] babbling) {
        int answer = 0;
        foreach(var k in babbling)  if(babble(k)) answer++;
        return answer;
    }
}

//그냥 귀찮은 구현 문제

//1. string을 하나씩 탐색하고 붙혀나가며 옹알이 단어가 있는지 확인.
//            s+=k;
//2. 옹알이 단어가 있음이 확인되면 붙히고 있던 string을 빈문자로 초기화시킴.
/*
            if(s=="ye" || s=="ma" || s == "woo" || s=="aya") {
                ...
                isBabble = true;
                befores = s;
                s = "";
            }
*/
//3. 옹알이가 부적격인 경우를 따져봄.
/*
    3-1. 옹알이의 최대 길이(위 문제에선 3이다.)를 넘어서까지 옹알이 단어가 발견되지 않은 경우
    3-2. 옹알이 끝 글자까지 확인했는데 여전히 stirng을 초기화 시키지 못한 경우
            else if(s.Length>=3 || (count == w.Length && s.Length!=0)){
                isBabble = false;
                break;
            }
    
    3-3. 이전에 발견한 옹알이 단어가 또다시 발견된 경우
            if(befores == s) {
                isBabble = false;
                break;
            }
*/

//4. 3번의 케이스가 단 하나라도 발견되면 즉시 break시키고 옹알이 단어가 아니라고 하면 됨.
//4. 3번의 케이스가 단 하나도 발견되지 않았으면 true반환시키고 옹알이 단어라고 하면 됨.
