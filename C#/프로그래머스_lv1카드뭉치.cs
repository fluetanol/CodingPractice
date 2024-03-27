//https://school.programmers.co.kr/learn/courses/30/lessons/159994
//프로그래머스lv1카드뭉치
//2024.03.27
//소요시간5분

using System;

public class 프로그래머스lv1카드뭉치 {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        string answer = "Yes";
        int c1 = 0;
        int c2 = 0;
        int g = 0;
        
        while(true){
            if(g == goal.Length) break;
            else if(c1<cards1.Length &&goal[g] == cards1[c1]) c1++;   
            else if(c2<cards2.Length &&goal[g] == cards2[c2]) c2++;    
            else{
                answer = "No";
                break;
            }
            g++;
        }
        return answer;
    }
}

//그냥 각각의 배열에 대한 인덱스값을 상황에 맞게만 올려주면 되는 쉬운 문제.