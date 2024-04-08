//https://school.programmers.co.kr/learn/courses/30/lessons/43163
//프로그래머스_lv3단어변환
//2024.04.06
//30분

using System;
using System.Collections.Generic;

public class 프로그래머스_lv3단어변환 {
    
    int BFS(HashSet<string> hs, string[] words, string begin, string target, int ans){
        if(begin == target) return hs.Count;
        else if(hs.Contains(begin))  return 9999999;

        hs.Add(begin);
        int min = 9999999;
        foreach(var k in words){
            if(hs.Contains(k)) continue;
            int count = 0;
            for(int i=0; i<begin.Length; i++){
                if(begin[i] != k[i]) count++;
            }
            if(count == 1){
                ans += 1;
                HashSet<string> hhs = new HashSet<string>(hs);
                int newans = BFS(hhs, words, k, target, ans);
                if(min>newans) min = newans;  
            }
        }
        return min;
    }
    
    public int solution(string begin, string target, string[] words) {
        int answer = 0;
        HashSet<string> hs = new HashSet<string>();
        answer = BFS(hs,words, begin, target, 0);
        if(answer == 9999999) answer = 0;
        return answer;
    }
}

//set안에 들어가있는 애들이 거쳐간 노드.
//단계수는 노드-1이므로, set이 마지막 노드를 넣기 전의 크기를 반환해주면
//해당 루트에서의 단계수가 나온다.
//이렇게 단계수를 리턴받아서 가장 작은 값으로 계속 갱신해주면 해결.