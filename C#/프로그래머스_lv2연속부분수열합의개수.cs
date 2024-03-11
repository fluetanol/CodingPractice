//https://school.programmers.co.kr/learn/courses/30/lessons/131701?language=csharp
//프로그래머스_lv2연속부분수열합의개수
//2024.02.20
//20분
using System;
using System.Collections.Generic;
using System.Linq;
public class Node
{
    int Value;
    public Node next = null;
    public Node(int val) => Value = val;
    public int getValue() => Value;
}

public class 프로그래머스_lv2연속부분수열합의개수
{
    public int solution(int[] elements)
    {
        int answer = 0;
        Node First = new Node(elements[0]);
        Node Next = First;

        for (int i = 1; i < elements.Length; i++)
        {
            Node temp = new Node(elements[i]);
            Next.next = temp;
            Next = temp;
        }
        Next.next = First;

        Node Pivot = First;
        List<int> SumList = new List<int>();

        //길이 i=1부터 i=전체 길이까지
        for (int i = 1; i <= elements.Length; i++)
        {
            bool isRepeat = false;
            //Pivot이 원점으로 돌아올때까지 반복
            while (Pivot != First || !isRepeat)
            {
                if (Pivot == First) isRepeat = true;
                int sum = 0;
                Node Temp = Pivot;
                //tmep(부분수열 시작점) 으로부터 길이만큼 주소 접근
                for (int j = 0; j < i; j++)
                {
                    sum += Temp.getValue();
                    Temp = Temp.next;
                }
                SumList.Add(sum);
                Pivot = Pivot.next;
            }
            Pivot = First.next;
        }
        // foreach(var i in SumList.Distinct().ToArray()) Console.Write(i + " ");
        return SumList.Distinct().ToArray().Length;
    }
}

//이런 문제는 DP로 풀면 속도 빨라지는건 팩트인데
//나같은 소시민은 아직 대가리가 깨질거같이 아프기 때문에
//Node개념으로 순환그래프를 만들면서 차례차례 다음 노드 접근 하는 방식으로 무식하게 풀었다.

//만약 이 방식을 개선시켜서 푼다면 
//딕셔너리나 트리등을 이용해서
//이전에 쓴 덧셈을 재활용하며 중복되는 덧셈을 줄여나가면서 풀어볼 수도 있을듯
//최악의 케이스에 1600ms 소모되서 불안한 구현은 맞음.

//다른 중요한 풀이
//이 방식이 진짜 DP로 푼 방식이다
//처음부터 n*n+1자리 배열을 만들어서
//원리 elements은 0번째,
//1번째 시행 수열합은 1번째...
//2번째 시행 수열합은 2번째...
//최종적으로 n번째 시행은 n번째 배열에 값을 저장하는 방식을 쓴다
//O(n^2)같지만 밑으로 내려갈수록 시행횟수가 대략 절반씩 줄어들기 때문에 O(nlogn)같은 복잡도를 지닌다... 
public class 프로그래머스_lv2연속부분수열합의개수2
{
    public int solution(int[] elements)
    {
        int n = elements.Length;
        HashSet<int> sum = new HashSet<int>();
        int[,] dp = new int[n, n + 1];
        for (int i = 0; i < n; i++)
        {
            dp[i, 1] = elements[i];
            sum.Add(elements[i]);
        }
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                dp[j, i] = dp[j, i - 1] + elements[(i + j - 1) % n];
                sum.Add(dp[j, i]);
            }
        }

        return sum.Count;
    }
}