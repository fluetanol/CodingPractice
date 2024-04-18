//https://school.programmers.co.kr/learn/courses/30/lessons/12927
//프로그래머스_lv3야근지수
//2024.04.18
//1시간

using System;
using System.Collections.Generic;
using System.Linq;

public class 프로그래머스_lv3야근지수
{
    public long solution(int n, int[] works)
    {
        long answer = 0;

        Array.Sort(works);
        Array.Reverse(works);

        int idx = 0;
        while (n > 0)
        {
            if (idx != works.Length - 1 && works[idx] > works[idx + 1])
            {
                works[idx]--;
                idx = 0;
            }
            else if (idx == works.Length - 1 || works[idx] == works[idx + 1])
            {
                works[idx]--;
                idx++;
            }
            idx = idx % works.Length;
            n--;

        }

        foreach (var k in works)
        {
            if (k < 0) return 0;
            else answer += k * k;
        }

        return answer;
    }
}

//수학적 특성을 이용해야 하는 문제...
//1^2과 2^2의 차이는 3이다.
//2^2과 3^2의 차이는 5다.
//3^2과 4^2의 차이는 7이다.
//4^2과 5^2의 차이는 9이다....

//어떤 수 a, b가 주어졌을때, a와 b를 각각 제곱한 것의 차이는 적어도 a와 b보단 크다. 
//이는 그 숫자가 클 수록 압도적으로 커짐.

//다시 말해, works배열 안에 있는 숫자들 중 큰 숫자들을 먼저 줄여 나가는 방식으로 구해야 한다는 것.

//Ex)7,6,5가 있다고 하면 7을 6으로 줄이는 것과 6을 5로 줄이는 것 중 위 수학적 특성 때문에 줄어드는 폭이 높은건 7을 줄이는 것이다.
//Ex) 10,6,4,3이 있다고 하면 10을 9로 줄이는 것과 6을 5로 줄이는 것중 10을 줄이는 게 더 크고
//계속 해서 9를 8로 줄이는 것이 6을 5로 줄이는 것보다 크다는 것도 알 수 있다.
//이런 식으로 가장 큰 최댓값들이 그 다음 큰 값이 될 때까지 전부 1씩 계속 빼가면서
//이 방법대로 n값이 0이 될 때까지 반복해주면 끝난다.

//물론 결국 가장 큰 수부터 작은 수 순서대로 1씩 뺴줘야 하는 작업이므로 정렬 알고리즘이 주된 문제라고 보면 된다.
//근데 정렬은 .Sort()쓰면 되서 날먹 가능

