//https://school.programmers.co.kr/learn/courses/30/lessons/12921
//프로그래머스_lv1소수찾기
//2024.03.13
//10분

using System;
using System.Collections.Generic;

public class 프로그래머스_lv1소수찾기
{
    public int solution(int n)
    {
        int answer = 0;
        HashSet<int> prim = new HashSet<int>();

        for (int i = 2; i * i <= n; i++)
        {
            if (!prim.Contains(i))
            {
                int k = i;
                int a = 2;
                while (k * a <= n)
                {
                    prim.Add(k * a);
                    a += 1;
                }
            }
        }
        answer = n - prim.Count - 1;
        return answer;
    }
}


//1. 소수찾기는 sqrt(n)까지만 찾아봐도 됨
//2. set안에는 소수가 아닌 놈들을 넣어 둠
//3. set안에 들어있지 않았던 숫자들은 소수임

//동작방식
//1은 예외 규칙이므로 뺀다 치면 2부터 시작
//2 -> set안에 없으므로 소수
//2의 배수들 -> 당연히 2를 최소 포함하는 비소수이므로 set에 넣어둠
//3 -> 2의 배수를 넣는 과정에서 3은 없을 것이므로 소수
//3의 배수들 -> 당연히 비소수들
//4 -> 2의 배수를 넣을 때 set에 담겼으므로 걸러짐
//5 -> 2,3의 배수 둘다에 속하지 않으므로 set에 없어서 소수
//....

//이런 규칙으로 k인 경우 set에 없다면 k보다 작은 숫자에 의한
//배수 판정이 안되었기 때문에 지금까지 set에 안담긴바, 소수가 맞으며
//set에 있는 경우 k보다 작은 숫자들 중 어떤 숫자의 배수라는 뜻이므로 소수가 아니임
//이런 방식으로 판정내는 알고리즘이 에라토스테네스의 체.

//위 방식에 따라서
//전체 n에서 set안에 있는 숫자들은 소수가 아닌 놈들이므로
//n - (set의크기)를 빼주면 소수의 갯수가 된다(여집합 개념)
//근데 본인은 귀찮아서 set안에 1을 빼먹었기 때문에 
// answer = n - prim.Count - 1;로 처리해버림...