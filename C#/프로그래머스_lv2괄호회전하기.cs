//https://school.programmers.co.kr/learn/courses/30/lessons/76502
//프로그래머스_lv2괄호회전하기
//2024.03.14
//25분

using System;
using System.Collections.Generic;

public class 프로그래머스_lv2괄호회전하기
{
    public int solution(string s)
    {
        int answer = 0;
        Queue<char> q = new Queue<char>();
        foreach (var i in s) q.Enqueue(i);
        for (int i = 0; i < s.Length; i++)
        {
            Stack<char> stack = new Stack<char>();
            foreach (var k in q)
            {
                if (stack.Count != 0 && stack.Peek() == '(' && k == ')')
                {
                    stack.Pop();
                }
                else if (stack.Count != 0 && stack.Peek() == '{' && k == '}')
                {
                    stack.Pop();
                }
                else if (stack.Count != 0 && stack.Peek() == '[' && k == ']')
                {
                    stack.Pop();
                }
                else stack.Push(k);
            }

            if (stack.Count == 0) answer += 1;
            q.Enqueue(q.Dequeue());
        }
        return answer;
    }
}


//문자열 돌리기는 큐쓰면 한번에 해결된다 (맨앞에 있는 놈을 뒤로 보내면 되므로)
//그리고 괄호판정은 스택을 쓰면 풀린다는 사실은 알고리즘 공부에서 공공연하게 배웠으므로 패스



public class 프로그래머스_lv2괄호회전하기2
{
    public int solution(string s)
    {
        int answer = 0;
        for (int i = 0; i < s.Length; i++)
        {
            if (IsCorrectBracket(s))
            {
                answer++;
            }
            s = s.Substring(1) + s[0]; // 문자열 회전
        }
        return answer;
    }

    private bool IsCorrectBracket(string s)
    {
        Stack<char> stack = new Stack<char>();
        foreach (char c in s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                stack.Push(c);
            }
            else
            {
                if (stack.Count == 0) return false;
                char top = stack.Pop();
                if ((top == '(' && c != ')') ||
                    (top == '[' && c != ']') ||
                    (top == '{' && c != '}'))
                {
                    return false;
                }
            }
        }
        return stack.Count == 0;
    }
}

// ...근데 gpt가 내놓은 답안도 비슷하면서 거의 똑같은 복잡도의 알고리즘을 내놓았는데
//웃기게도 이 답안이 내 답안보다 실 성능이 네배나 더 빨랐다
//딱 하나 차이라면 문자열을 순환시키는데에 나는 큐를 쓰고 얘는 substring을 썼다는 건데
//대체 뭔 차이에서 시작된거지????
//참고로 dequeue와 enqueue의 성능은 O(1)