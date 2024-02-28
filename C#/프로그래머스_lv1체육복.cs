//https://school.programmers.co.kr/learn/courses/30/lessons/42862#
//프로그래머스lv1체육복
//2024.02.29
//소요시간30분

using System;
using System.Linq;
using System.Collections.Generic;

public class 프로그래머스lv1체육복
{
    public int solution(int n, int[] lost, int[] reserve)
    {
        int answer = n;

        Dictionary<int, bool> lostDic = new Dictionary<int, bool>();
        foreach (var i in lost) lostDic[i] = true;
        for (int i = 0; i < reserve.Length; i++)
        {
            if (lostDic.ContainsKey(reserve[i]))
            {
                lostDic.Remove(reserve[i]);
                reserve[i] = -1;
            }
        }
        Dictionary<int, bool> lostDicCopy = new Dictionary<int, bool>(lostDic);

        foreach (var i in reserve)
        {
            if (i == -1) continue;
            if (lostDicCopy.ContainsKey(i + 1)) lostDicCopy.Remove(i + 1);
            else if (lostDicCopy.ContainsKey(i - 1)) lostDicCopy.Remove(i - 1);
            if (lostDic.ContainsKey(i - 1)) lostDic.Remove(i - 1);
            else if (lostDic.ContainsKey(i + 1)) lostDic.Remove(i + 1);

        }
        int length1 = lostDic.Keys.ToArray().Length;
        int length2 = lostDicCopy.Keys.ToArray().Length;

        answer = length1 > length2 ? answer - length2 : answer - length1;
        return answer;
    }
}


//reserve배열에서 원소를 하나씩 꺼내서
//원소 i보다 1크거나 1작거나 같은 원소가 lost배열에도 있는지 확인하면 되는데,
//확인 작업, 찾기 작업은 딕셔너리가 성능이 좋아서 딕셔너리를 썼다.
//다만 이 문제 특성상 배열크기가 30이 최대여서 사실 리스트에서 find돌렸어도 맞았을듯

//그런데 다만, 다음과 같은 예외를 잘 고려해야한다.
//1. reserve의 원소 i와 똑같은 원소가 있는 경우, 그 원소부터 무조건 1대1 대응해서 지워줘야 함
//이는 문제의 규칙 때문에 그렇게 처리해야한다. 첫번째 remove반복문이 그 역할을 한다.

//2. i-1원소를 지우는 것과 i+1원소를 지우는 것 둘 중 어느쪽을 먼저 지우느냐에 따라 뒤에 있을 원소 삭제처리에 영향을 미침
//예를 들어 
//lost = [1,3,6,7,9] reserve = [8,10] 라고 하면
//i=8일때 i-1부터 지우면 7을 지우는 대신 9를 못지우고, i=10일때 9를 지울 수 있게 된다. 따라서 lost는 1,3,6만 남는다.
//그런데 i+1부터 지우면 9를 지우는 대신 7을 못지우고, i=10일때 9를 못지우고 아무 역할도 못하게 된다. 따라서 lost는 1,3,6,7이 남는다.
//최종적으로 lost에 남게 되는 배열이 차이가 생기면서 값이 달라진다.
//이 때문에 딕셔너리를 하나 더 파서 lostDicCopy i+1을 먼저 지우는 경우랑 i-1을 먼저 지우는 경우 중 더 나은 경우의 값을 내놓도록 했다.



//다른 더 나은 풀이
//이 풀이는 n명에 대한 정보를 담을 배열을 만들고
//체육복이 없으면 0, 하나 있으면 1, 두개 있으면 2의 정보를 담는다.
//앞배열과 뒤배열의 차이가 2(즉, Math.Abs(Person[i] - Person[i + 1]) == 2)라면
//i또는 i+1위치 둘중 하나는 반드시 체육복 두개인 놈과 체육복이 없는 놈이 존재한다는 것이므로
//각 배열을 1, 1로 나누어서 체육복을 나누는 것 같은 표현을 한다.
//그리하여 최종적으로 나눠준 후에도 체육복이 없는 애들을 count해서 전체 수에서 빼주는 방식이다.

//애초에 내 방식은 딕셔너리전환 +Toarray연산때문에 시간소모가 좀 있었는데
//얘는 단순 반복만 몇번 하는 게 끝인지라 시간이 오래 걸리지 않는다는 장점이 있었다.
//성능차이가 무려 6배 차이...
//물론 toarray연산은 단순이 딕셔너리 크기 구하려고 쓴거여서 걍 length변수 두고 remove될떄마다 1씩 감소시키는 방식을 쓰면
//성능을 30%정도 개선시킬수 있다.
public class 프로그래머스lv1체육복2
{
    public int solution(int n, int[] lost, int[] reserve)
    {

        int[] Person = new int[n];
        for (int i = 0; i < n; i++)  Person[i] = 1;
        for (int i = 0; i < lost.Length; i++) Person[lost[i] - 1]--;
        for (int i = 0; i < reserve.Length; i++)  Person[reserve[i] - 1]++;

        for (int i = 0; i < Person.Length - 1; i++)
        {
            if (Math.Abs(Person[i] - Person[i + 1]) == 2)
            {
                Person[i] = 1;
                Person[i + 1] = 1;
            }
        }
        int count = 0;
        for (int i = 0; i < Person.Length; i++)
        {
            if (Person[i] == 0) count++;
        }
        return Person.Length - count;
    }
}