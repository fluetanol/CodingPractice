//https://school.programmers.co.kr/learn/courses/30/lessons/118667
//프로그래머스_lv2두큐합같게만들기
//2024.04.13
//3시간;; (시간초과)


using System;
using System.Linq;
using System.Collections.Generic;
public class 프로그래머스_lv2두큐합같게만들기
{
    public int solution(int[] queue1, int[] queue2)
    {
        int answer = -1;
        List<(int, int)> l = new List<(int, int)>();
        long sum = 0;
        long sum2 = 0;
        for (int i = 0; i < queue1.Length; i++)
        {
            sum += queue1[i] + queue2[i];
            sum2 += queue1[i];
        }
        if (sum2 == sum / 2) return 0;

        int[] queue = queue1.Concat(queue2).ToArray();
        int[] rqueue = queue2.Concat(queue1).ToArray();

        int iidx = 0;
        int idx = 0;
        long ssum = 0;

        while (true)
        {
            if (ssum == sum / 2) l.Add((iidx, idx));
            if (ssum + queue[idx] > sum / 2)
            {
                ssum -= queue[iidx];
                iidx = (iidx + 1) % queue.Length;
                continue;
            }
            ssum += queue[idx];
            idx = (idx + 1);
            if (idx == queue.Length) break;
            idx = idx % queue.Length;
        }

        iidx = 0;
        idx = 0;
        ssum = 0;
        while (true)
        {
            if (ssum == sum / 2) l.Add((iidx, idx));
            if (ssum + rqueue[idx] > sum / 2)
            {
                ssum -= rqueue[iidx];
                iidx = (iidx + 1) % rqueue.Length;
                continue;
            }
            ssum += rqueue[idx];
            idx = (idx + 1);
            if (idx == rqueue.Length) break;
            idx = idx % rqueue.Length;
        }


        if (l.Count == 0) answer = -1;
        else
        {
            foreach (var k in l)
            {
                Console.WriteLine(k);
                iidx = k.Item1;
                idx = k.Item2;
                int c = 0;

                //q1에서만 발견
                if (idx <= queue.Length / 2) c = (idx - iidx) + (queue.Length / 2) + (iidx * 2);
                //q2에서만 발견
                else if (iidx >= queue.Length / 2) c = queue1.Length + (idx - iidx) + (iidx - queue.Length / 2) * 2;
                //q1, q2에 걸터서 발견
                else if (iidx < queue.Length / 2 && idx > queue.Length / 2) c = iidx + (idx - queue.Length / 2);
                if (c < answer || answer == -1) answer = c;
            }
        }
        return answer;
    }
}


//사실 큐문제를 빙자한 원형배열의 부분합을 구하는 문제다...
//그 이유가 큐에서 원소를 빼면 상대 큐로 넣어야 한다는 규칙 때문이다.
//큐에 넣은 것과 빼는 것은 선입선출이라는 규칙 때문에 항상 나열된 수 순서가 그대로 유지된다.
//그런고로 큐 두개를 이어 붙혀보면
//Ex)
/*
queue1 = [3, 2, 7, 2]
queue2 = [4, 6, 5, 1]
*/

//[3,2,7,2,4,6,5,1] 이거나 [4,6,5,1,3,2,7,2] (큐1+큐2 또는 큐2+큐1, 배열 나열 방식이 다르니 둘은 다른 케이스가 맞음)
//이런 원소 나열에서 전체 합의 절반이 되는 값을 가진 원소 부분합을 구해주면 된다...

/* O(n)으로 부분합 구하는 코드
        while (true)
        {
            if (ssum == sum / 2) l.Add((iidx, idx));
            if (ssum + queue[idx] > sum / 2)
            {
                ssum -= queue[iidx];
                iidx = (iidx + 1) % queue.Length;
                continue;
            }
            ssum += queue[idx];
            idx = (idx + 1);
            if (idx == queue.Length) break;
            idx = idx % queue.Length;
        }
*/

//부분합이 나올수 있는 인덱스 구간이 한두개가 아니기 때문에 모든 인덱스 구간을 구해주고
//그걸 리스트에 담는다

//이후 인덱스 구간의 특성에 따라 세 가지 케이스로 나눠서 풀면 된다

//1. 큐 1에만 구간이 주어진 경우
//위치를 역으로 바꿔야 하는 케이스
// [0 [1 2] 3 4][5 6 7 8 9]
//라면, Q2에 있는 모든 원소를 Q1로 보낸 후 
//([0 [1 2] 3 4 5 6 7 8 9] [])
//Q1의 [1,2]앞에 있는 원소들을 Q2의 뒷꽁무니에 보내기 위해 Q2->Q1 두번에 걸쳐서 옮겨준다.
//([[1 2] 3 4 5 6 7 8 9 0] [])
//이 후 앞에 남은 [1,2]만 Q2로 보내준다. 다시 말해, [3 4 5 6 7 8 9 0] [1 2] 면 됨
//([[3 4 5 6 7 8 9 0] [1 2])

//2. 큐 2에만 구간이 주어진 경우
//위치를 역으로 바꿔야 하는 케이스
//[0 1 2 3 4][5 [6 7] 8 9]
//[5 6 7]을 큐 1으로 보내야 함. 1번케이스와 비슷하게 하면 된다.
//[][[5 [6 7] 8 9 0 1 2 3 4] -> [5 [6 7]] [8 9 0 1 2 3 4] -> [6 7] [8 9 0 1 2 3 4 5]

//3. 큐 1과 2에 걸쳐서 구간이 주어진 경우
//[0 [1 2 3 4]  [5] 6 7 8 9]
//정직하게 구간을 Q1로 보낸다는 느낌으로 풀면 된다.
//Q1에 범위에 들지 않은 모든 원소를 Q2로 보낸 후
// [[1 2 3 4]] [5] 6 7 8 9 0]
//Q2의 범위에 든 모든 원소를 Q1로 보내면 끝
//[[1 2 3 4 5]] [6 7 8 9 0]

//위 세가지 케이스로 나눠서 발견한 규칙 대로 수학적인 식을 세워 
//아까 리스트에 담은 모든 구간의 케이스에 대한 큐의 옮김 횟수를 구하고,  그 중 최솟값을 ANSWER로 삼으면 답이 된다.
/*
  foreach(var k in l){
                Console.WriteLine(k);
                iidx = k.Item1;
                idx = k.Item2;
                int c = 0;

                //q1에서만 발견
                if(idx <= queue.Length/2)  c = (idx-iidx) + (queue.Length/2) + (iidx*2);
                //q2에서만 발견
                else if(iidx >= queue.Length/2)  c = queue1.Length + (idx-iidx) + (iidx - queue.Length/2)*2;
                //q1, q2에 걸터서 발견
                else if(iidx < queue.Length/2 && idx > queue.Length/2)  c = iidx + (idx - queue.Length/2);  
                if(c < answer || answer == -1)  answer = c;
            }

 */


// 예외 케이스
//1. 양쪽 큐의 합이 처음부터 똑같은 경우
//[3 4 5 6] [2 7 4 5]
//이런 경우 처움부터 양쪽합이 모두 18이여서 옮길 필요가 없음 -> 걍 0 반환

//2. 리스트에 담긴 구간이 없는 경우
// 전체합/2 를 만들 수 있는 부분합이 없다는 것이므로, 애초에 이 큐 두개로는 양쪽 합을 같게 만들 수
// 없음을 의미함. -1 반환.


// 부분합(어찌보면 DP) + 그리디 + 수학적 규칙...
// 역시 카카오 인턴십 문제다운 빡빡한 문제
// 아이디어를 얻는 부분에서 시간이 걸릴 것 같았다.