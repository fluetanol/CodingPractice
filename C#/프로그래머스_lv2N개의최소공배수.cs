//https://school.programmers.co.kr/learn/courses/30/lessons/12953
//프로그래머스_lv2N개의최소공배수
//2024.02.26
//15분

using System;
using System.Collections.Generic;
public class 프로그래머스_lv2N개의최소공배수
{
    public int solution(int[] arr)
    {
        int answer = 0;
        Dictionary<int, int> mularr = new Dictionary<int, int>();
        int count = 1;
        bool isLoop = true;
        while (isLoop)
        {
            for (int i = 0; i < arr.Length; i++)
            {
                int num = arr[i];

                if (!mularr.ContainsKey(num * count)) mularr[num * count] = 1;
                else mularr[num * count] += 1;

                if (mularr[num * count] >= arr.Length)
                {
                    answer = num * count;
                    isLoop = false;
                }
            }
            count += 1;
        }
        return answer;
    }
}

//알고리즘은 이렇다.
//딕셔너리에 일단 배수가 되는 숫자들을 막 넣는다.
//배수가 되는 숫자를 처음 넣으면 value를 1을 넣고  -> (!mularr.ContainsKey(num * count))
//그 뒤로 중복되는 배수였다면 value를 1씩 카운트 시켜준다. -> else mularr[num * count] += 1;
//만약 공배수라면 value는 숫자의 갯수만큼 카운트가 되어있을 것이고 -> (mularr[num * count] >= arr.Length)
//이는 증가율이 가장 낮은 수로 부터 발견될 것이므로 처음에 발견된 공배수가 최소공배수가 된다는 것을 항상 보장한다.



public class 프로그래머스_lv2N개의최소공배수2 {
    public int solution(int[] arr) {

        int answer = arr[0];

        for (int i = 1; i < arr.Length; ++i)
            answer *= arr[i] / Gcd(answer, arr[i]);

        return answer;
    }

    public int Gcd(int a, int b)
    {
        while (b != 0)
        {
            int r = a % b;
            a = b;
            b = r;
        }

        return a;
    }
}

//위 방식은 유클리드 호제법이라는 유명하고 효율 좋은 최소공배수 알고리즘이니 참고
//https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95

