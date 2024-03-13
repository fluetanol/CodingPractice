//https://school.programmers.co.kr/learn/courses/30/lessons/68644?language=csharp
//프로그래머스_lv2카펫
//2024.03.14
//15분

using System;
using System.Collections.Generic;

public class Solution {
    public int[] solution(int brown, int yellow) {
        int[] answer = new int[2] {0,0};
        int blockCount = brown + yellow;
        for(int i=1; i*i<=blockCount; i++){
            if(blockCount%i == 0){
                if(2*(blockCount/i)+2*(i-2) == brown){
                    answer[0]= blockCount/i;
                    answer[1] = i;
                }
            }
        }
        return answer;
    }
}

//완전 탐색 문제들 중에서도 너무 쉬웠던 문제...
//갈색이 외곽선 한칸만 차지한다는 조건 때문에
//일정한 수식을 세우고, 주어진 칸수 내에서 brown이 외곽선을 차지할 수 있는 경우의 수만 찾으면 된다.
//참고로 외곽선 칸 수 공식은 2*a + 2(b-2), a는 가로길이, b는 세로길이이며, a>=b.
