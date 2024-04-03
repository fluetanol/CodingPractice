//https://school.programmers.co.kr/learn/courses/30/lessons/42578
//프로그래머스_lv2의상
//2024.04.03
//n일 걸림 (시간초과...)

using System;
using System.Collections.Generic;
using System.Linq;

public class 프로그래머스_lv2의상 { 
    
    void Comb(int choose, int depth, int idx, int[] vals, int sum, ref int answer){
        if(choose == depth){
            for(int i=idx; i<vals.Length; i++){
                sum *= vals[i];
                answer+= sum;
            }
            return;
        }
        else{
            for(int i=idx; i<vals.Length; i++){
                int ssum = sum;
                ssum *= vals[i];
                answer+= ssum;
                Comb(choose, depth+1, i+1, vals, ssum, ref answer);    
            }
        }
    }

    public int solution(string[,] clothes) {
        int answer = 0;
        Dictionary<string,int> d= new Dictionary<string,int>();
        for(int i=0; i<clothes.Length/2; i++){
            string c = clothes[i,1];
            if(d.ContainsKey(c)) d[c]++;
            else d[c] = 1;
        }     
        int[] vals = d.Values.ToArray();
        Comb(vals.Length-1, 0, 0, vals, 1, ref answer);
        return answer;
    }
}

// 모든 경우의 수를 전부 둘러봐야 하는 문제...
// 조합 알고리즘 모르면 풀기 어려웠던 문제
// 나중에 다시 풀어볼 만한 가치가 있음.