//https://school.programmers.co.kr/learn/courses/30/lessons/42860
//프로그래머스_lv2조이스틱
//2024.03.30
//5시간...(시간초과)

using System;
using System.Collections.Generic;
public class Solution {
    //take char up down min count
    void MinUpDown(char k, ref int ans){
        if(k<='N')  ans += k - 'A';
        else   ans += 'Z' - k + 1; 
   }
    
    
    //direction true = right, false = left
    void Move(bool direction, int len, ref int i){
        i = direction ? i+1 : i-1; 
        i = (i+len) % len;
    }
    
    //get distance next node;
    (int,int) Distance(HashSet<int> h, bool direction, string name, int idx){
        int i = idx;
        int d = 1;
        while(true){
            Move(direction, name.Length, ref i);
            if(name[i] != 'A' && !h.Contains(i)) break;
            else d++;
        }
        return (d, i);
    }


    int shortRt(HashSet<int> h, string name, int validlen, int idx, int answer){
        if(validlen == 0) return answer;
        char current = name[idx];
        var d1 = Distance(h, true, name, idx);
        var d2 = Distance(h, false, name, idx);
        if(!h.Contains(idx) && name[idx]!='A') {
            MinUpDown(current, ref answer);
            h.Add(idx);
        }
        if(h.Count >= validlen) return answer;
        HashSet<int> h1 = new HashSet<int>(h);
      int a1 = shortRt(h, name, validlen, d1.Item2 ,answer+d1.Item1);
     int a2 = shortRt(h1, name, validlen, d2.Item2 ,answer+d2.Item1);
        answer = a1 >= a2 ? a2 : a1;
        //answer += d;
        
        return answer;
    }
    
    
    public int solution(string name) {
        int answer = 0;
        int validlen = name.Replace("A","").Length;
        int idx = 0;
        HashSet<int> h = new HashSet<int>();

        answer = shortRt(h,name, validlen, idx, answer);
        return answer;
    }
}

//그리디 문제인줄 알았는데 그냥 완전탐색 문제였던 어처구니 없는 문제

//문자를 만드는 규칙은 문자 'N'을 기준으로
//N 아래 글자는 k - 'A', N 위 글자는 'Z'-k+1을 연산하면 된다.

//이 중 글자 A는 그냥 건너뛰어도 되는 글자기 때문에,
//좌우 조이스틱 움직임의 최적화에 영향을 미치는 요소가 되는데
//쉽게 생각해보면, 그래프에서의 간선의 가중치 같은 역할을 한다.

//EX BAAC

//이러면 B->C로 가는 루트가 두가지가 있는데
//첫번째는 B에서 거꾸로 가서 C로 가는 가중치가 1인 루트와
//두번째는 A를 거쳐서 가는 가중치가 3인 루트가 있는 셈이다.
//당연히 가중치가 낮은 루트를 따라 가는게 좋을 확률이 높으니까 
//거꾸로 가는게 더 낫다

//근데 위와 같이 그리디 하게 풀면 놀랍게도 특정 케이스에서 막힌다.
//그니까, 매 순간순간의 최선의 선택만을 해버리면
//전체적으로는 꼭 최선은 아닌 값이 나오는 케이스가 있다는 것이다....

//1. RCETAAAAVUEAETZAAAK
//이 케이스의 경우 처음에 R이 C로 가는 경우랑 K로 가는 경우 둘다
//가중치가 1로 동일하기 때문에 어느 방향을 선택해서 가냐에 따라
//전체 결과가 달라지는 케이스다.
//그리고 실제로 K쪽으로 가야 더 나은 케이스가 되는데, 만약 IF문 제어를
//같은 가중치인 경우 그냥 오른쪽으로 나아가게 했다면 이 케이스에서 틀리게 된다

//2. BBBBAAABA
//이 케이스는 결론적으로 말하면 1번째 글자 다음엔
//좌로 움직여서 8번째 글자로 이동해야 답이나오는 케이스다.
//근데 그리디하게 푼다면 첫번째 글자 좌방향으론 A때문에 가중치가 2가 되고
//두번째 글자 B로 가는 건 가중치가 1이기 때문에 우방향으로 움직이게 되면서 오답이 나온다.
//문제 카테고리는 그리디면서 테스트케이스는 완전탐색해야 풀 수 있는 예시를 갖다 놓고 앉아있음...


//위와 같은 두 케이스 때문에 그냥 BFS, DFS써서 
//좌 방향으로 가는 경우, 우방향으로 가는 경우 모두를 따져보고
//그 중 가장 낮은 값을 가진 ANSWER를 정답으로 만드는게 낫다.
//어차피 글자 수도 최대 20이여서 크리티컬할 정도의 재귀를 하진 않음
//에후...