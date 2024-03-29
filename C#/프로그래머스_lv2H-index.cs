//https://school.programmers.co.kr/learn/courses/30/lessons/42747#fn1
//프로그래머스lv2H-Index
//2024.03.29
//5시간 (시간초과);;


using System;
using System.Collections.Generic;
public class 프로그래머스lv2H_Index {
    public int solution(int[] citations) {
        int answer = 0;
        Array.Sort(citations);
        for(int i=citations.Length-1; i>=0; i--){
            if(citations[i]<citations.Length-i) break;
            else answer = citations.Length-i;
            
        }
        return answer;
    }
}

//시발 문제 말뜻이해가 더 어려웠던 문제.
//정렬을 하면 된다는 것 까지 했다면
//그 뒤부터는 문제 말뜻 이해에 달려있는데
//그걸 못해서 직접 h-index관련 정보 담긴 참고 위키 링크를 봐서
//주어진 함수 식 그대로 풀었음.

//위키내용을 대충 훑어보니 인용 횟수와 논문을 내림차순 정렬했을때의 인덱스를 비교해서
//인덱스 >= 인용 횟수가 되게 만드는 인덱스의 최댓값 찾으라는 내용이였다.
//예를 들면 뭐 이런식이다.

// 1 3 7 7 8 9 4 5 4

//내림차순 하면

// 9 8 7 7 5 4 4 3 1

// 첫 인덱스부터 쭉쭉 내려가보자.

// index = 1, val = 9, 인용횟수 > index
// index = 2, val = 8, 인용횟수 > index
// index = 3, val = 7, 인용횟수 > index
// ...
// index = 5, val = 5, 인용횟수 = index
// 만약, 이 뒤로 더 넘어간다면 index가 val보다 클 것임이 틀림없으므로
// 딱 이 위치에서 break시켜준다.
// break된 시점에서의 index는 5이므로, h-index는 5다.
// 문제 이해력 기르는 국어 능력도 중요한 코테문제였다...