//https://school.programmers.co.kr/learn/courses/30/lessons/42628
//프로그래머스_lv3이중우선순위큐
//2024.03.11
//30분


using System;
using System.Collections.Generic;
using System.Linq;

public class 프로그래머스_lv3이중우선순위큐
{
    public int[] solution(string[] operations)
    {
        int[] answer = new int[] { 0, 0 };
        List<int> list = new List<int>();

        foreach (var i in operations)
        {
            var opr = i.Split(" ");
            var val = int.Parse(opr[1]);

            if (opr[0] == "I")
            {
                bool insert = false;
                for (int k = 0; k < list.Count; k++)
                {
                    if (val <= list[k])
                    {
                        list.Insert(k, val);
                        insert = true;
                        break;
                    }
                }
                if (!insert) list.Add(int.Parse(opr[1]));
            }
            else if (opr[0] == "D" && val == 1 && list.Any()) list.RemoveAt(list.Count - 1);
            else if (opr[0] == "D" && val == -1 && list.Any()) list.RemoveAt(0);
        }

        if (list.Any())
        {
            answer[0] = list[list.Count - 1];
            answer[1] = list[0];
        }
        return answer;
    }
}

//명령어가 10000000개나 있을 수 있다는 조건 때문에 개쫄았는데
//그냥 배열로 풀어도 생각보다 잘 되었다..
//배열 우선순위큐는 삭제는 양끝만 처리해주면 되서 O(1)로 어마어마하게 빠르지만
//원소를 넣는 순간 정렬작업을 위해 배열을 뒤적거려야한다는 특성상
//add할때마다 항상 O(N)이기 때문에 매번 들어오는 원소가 최댓값이면 최악의 결과가 나온다...
//그래서 최악의 케이스에서 시간초과가 나올줄 알았는데...
//의외로 아니였음 ㅋ
//참고로 최악의 케이스인 경우(n=10000000, input만 있고 remove는 없음, 들어올때마다 최댓값)
//O(n(n+1)/2) == O(n^2)이다 (add할때마다 (1+2+3+4+....+10000000)만큼 둘러봄)


//참고로 add와 remove모두 평균적이고 안정적인 속도를 내고 싶다면 그냥 binary tree를 구현하면 되는데,
//그 또한 input에 따라 편향 트리가 나오면 tree의 의미가 퇴색되니까 머리 아프게 감싸지말고 배열로 풀자...
//뭐? 그럼 balance tree로 구현하겠다고???
//큐 하나 구현하겠다고 미친 소리 하지 마라...