//https://school.programmers.co.kr/learn/courses/30/lessons/42840
//프로그래머스_lv2모의고사
//2024.04.04
//15분


using System;
using System.Collections.Generic;
public class 프로그래머스_lv2모의고사 {
    public int[] solution(int[] answers) {
        int[] t1 = new int[]{1,2,3,4,5};
        int[] t2 = new int[]{2,1,2,3,2,4,2,5};
        int[] t3 = new int[]{3,3,1,1,2,2,4,4,5,5};
        int[] correct = new int[3];
        for(int i=0; i<answers.Length; i++){
            if(t1[i%t1.Length] == answers[i]) correct[0]++;
            if(t2[i%t2.Length] == answers[i]) correct[1]++;
            if(t3[i%t3.Length]==answers[i]) correct[2]++;
        }
        
        List<int> ans = new List<int>();
        int max = -1;
        for(int i=0; i<3; i++){
            if(max < correct[i]) {
                max = correct[i];
                ans.Clear();
                ans.Add(i+1);
            }
            else if(max == correct[i])  ans.Add(i+1);
        }
        int[] answer = ans.ToArray();
        
        return answer;
    }
}


//규칙에 맞게 계속 인덱스를 돌려가면서 각 수포자별로 몇개 맞는지 체크하고
//max값을 가진 인덱스를 나열해서 출력하면 되는 문제.
//왜 lv2인거임?