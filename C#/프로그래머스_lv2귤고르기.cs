//https://school.programmers.co.kr/learn/courses/30/lessons/138476
//프로그래머스_lv2귤고르기
//2024.03.01
//30분

using System;
using System.Collections.Generic;
using System.Linq;

public class 프로그래머스_lv2귤고르기
{
    public int solution(int k, int[] tangerine)
    {
        int answer = 0;
        int sum = 0;
        Dictionary<int, int> CountDic = new Dictionary<int, int>();
        foreach (var i in tangerine)
        {
            if (CountDic.ContainsKey(i)) CountDic[i]++;
            else CountDic[i] = 1;
        }
        int[] keyArray = CountDic.Values.ToArray();
        Array.Sort(keyArray);

        for (int i = keyArray.Length - 1; i >= 0; i--)
        {
            sum += keyArray[i];
            if (k <= sum) break;
            answer += 1;
        }

        return answer + 1;
    }
}

//딕셔너리에 각 숫자가 가지고 있는 갯수를 구하고
//이를 정렬한 후,
//k를 넘어갈때까지 가장 큰 수 순서로 더하고,
//최종적으로 더한 횟수를 구해주면 된다.

//무슨 원리냐면, 결국 귤의 종류가 최소가 되려면 최대한 많은 종류부터 넣어둬야
//넣을 수 있는 귤의 종류가 최소가 된다는 원리를 이용한 것이다.
//상식적으로 생각해보면
//10을 만들기 위해 1,2,3,4,5,6,7,8,9의 숫자를 최소로 더해서 만들어보라고 한다면
//굳이 어렵게 1+2+3+4로 하지 않고 1+9를 쓰지 않겠는가?
//9가 큰 수 이기 때문에 10에 도달할 수 있는 가장 빠른 루트라는게 직관적으로 받아들여지기 때문에
//이런 방법을 사용 한 것이다. (그리디 알고리즘이라면 그리디 알고리즘인듯)


//그런데 다른놈이 푼거 보니까 저 dictionary.value를 배열화 시키는 걸
//List()화 시키니까 조금 더 성능이 빨라지는 현상이 있어보였음
//뭐냐 대체