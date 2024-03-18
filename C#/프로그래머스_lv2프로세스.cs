//https://school.programmers.co.kr/learn/courses/30/lessons/43165
//프로그래머스_lv2프로세스
//2024.03.14
//25분


using System;
using System.Collections.Generic;

public class 프로그래머스_lv2프로세스
{
    public int solution(int[] priorities, int location)
    {
        int answer = 0;
        Queue<int> q = new Queue<int>();
        Queue<int> p = new Queue<int>();
        for (int i = 0; i < priorities.Length; i++)
        {
            q.Enqueue(priorities[i]);
            p.Enqueue(i);
        }
        while (true)
        {
            int priority = q.Dequeue();
            int loc = p.Dequeue();
            bool isBig = false;
            foreach (var k in q)
            {
                if (k > priority)
                {
                    q.Enqueue(priority);
                    p.Enqueue(loc);
                    isBig = true;
                    break;
                }
            }
            if (!isBig)
            {
                answer += 1;
                if (loc == location) break;
            }
        }
        return answer;
    }
}


//걍 문제에 나온 조건 그대로 구현하면 되는 문제
//근데 문제 제대로 안읽기도 했고 
//입출력 예시가 오히려 더 헷갈린 느낌이라 구현 시간 두배로 걸림 하...
