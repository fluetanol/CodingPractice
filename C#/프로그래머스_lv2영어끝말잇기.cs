//https://school.programmers.co.kr/learn/courses/30/lessons/12981
//프로그래머스_lv2영어끝말잇기
//2024.03.22
//10분

using System;
using System.Collections.Generic;

class 프로그래머스_lv2영어끝말잇기
{
    public int[] solution(int n, string[] words)
    {
        int[] answer = {0,0};

        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
        HashSet<string> hs_word = new HashSet<string>();
         
        int idx = 0;
        char beforestr = words[0][0];
        System.Console.WriteLine(beforestr);
        foreach(var k in words){
            if(hs_word.Contains(k) || beforestr != k[0] || k.Length == 1){
                answer[0] = idx % n + 1;
                answer[1] = idx/n + 1;
                break;  
            }
            else {
                beforestr = k[k.Length-1];
                hs_word.Add(k);
            }
            idx++;
        }
        return answer;
    }
}

//간단한 구현 문제.

//앞사람이 말한 단어의 마지막 문자로 시작하는 단어를 말해야 합니다.
//이전에 등장했던 단어는 사용할 수 없습니다.
//한 글자인 단어는 인정되지 않습니다.

//라는 세 가지 조건을 전부 만족하도록 구현만 하면 된다...