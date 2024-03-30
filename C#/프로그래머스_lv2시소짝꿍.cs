//https://school.programmers.co.kr/learn/courses/30/lessons/152996
//프로그래머스_lv2시소짝꿍
//2024.03.30
//3시간

using System;
using System.Collections.Generic;

public class 프로그래머스_lv2시소짝꿍 {
    HashSet<(float,float)> h = new HashSet<(float, float)>();
    Dictionary<float, long> d = new Dictionary<float,long>();
    
    public long solution(int[] weights) {
        long answer = 0;   
        float[] ratios = new float[4]{1,2,3/2f,4/3f};
        Array.Sort(weights);
        
        foreach(var k in weights){
            if(d.ContainsKey(k)) d[k]++;
            else d[k] = 1;
        }
        foreach(var w in weights){
            foreach(var r in ratios){
                float wr = (float)w * r;
                if(d.ContainsKey(wr) && !h.Contains((w,wr)) && wr != w){
                    answer += d[w] * d[wr];
                    h.Add((w,wr));
                }
                else if(d.ContainsKey(wr) && !h.Contains((w,wr)) && wr == w){
                    answer += (d[wr] * (d[wr]-1))/2;
                    h.Add((w,wr));
                }
            }
        }
        return answer;
    }
}

//사실 문제 조건 이해를 제대로 못해서 헤맨 문제
//가령 [100,100,100]이라고 할떄
//나올 수 있는 순서쌍은 당연히(100,100)인데
//100N을 가진 서로 다른 세 사람이므로 각각 다른 쌍으로 취급해야한다
//다시 말해 (0,1), (0,2),(1,2)로 나눠서 3가지의 경우가 나온다는 것.

//이를 위해 각 숫자에 대응되는 인간이 몇명이 있는지 딕셔너리로 기록하고
//비율에 딱 맞는 순서쌍이 등장하면 
//딕셔너리에 있는 인원수를 이용해서 경우의 수를 처리해주고
/*
    w와 wr이 달라서 각각에서 한명씩 뽑으면 되는 경우
    answer += d[w] * d[wr];

    w와 wr이 같아서 2명 뽑기를 해야 하는 경우 (비율이 1인 케이스)
    answer += (d[wr] * (d[wr]-1))/2;
*/
//그 경우의 수들을 answer에 더하는 방식을 사용했다.
//만약 순수하게 가능한 몸무게의 순서쌍만 구하라 했다면 그냥 HashSet의 카운트를 answer로 해도 되는게 맞았음.

//아무리 봐도 문제 난이도가 높을수록 문제 이해하는게 힘들어지는 느낌...


using System;

public class 프로그래머스_lv2시소짝꿍2 {
    public long solution(int[] weights) {
        int weightsLength = weights.Length;

        long answer = 0;

        int[] weightsDisTance = new int[6001];
        int[] weightsreal = new int[2001];

        for(int i=0;i<weightsLength;i++)
        {
            int d2 = weights[i]*2;
            int d3 = weights[i]*3;
            int d4 = weights[i]*4;


            answer += weightsDisTance[d2];
            answer += weightsDisTance[d3];
            answer += weightsDisTance[d4];

            if(weightsreal[weights[i]] > 0)
            {
                answer -= weightsreal[weights[i]] * 2;
            }

            weightsreal[weights[i]]++;
            weightsDisTance[d2]++;
            weightsDisTance[d3]++;
            weightsDisTance[d4]++;

        }
        return answer;
    }
}

//이건 dp로 푼 방식이고
//내가 푼 방식보다 30배는 더 빨랐다
//이정도 성능 차이면 코드 해석해볼 필요 있을듯