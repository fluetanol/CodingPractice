//https://school.programmers.co.kr/learn/courses/30/lessons/43162#
//프로그래머스_lv2네트워크
//2024.04.05
//1시간

using System;
using System.Collections.Generic;

public class S프로그래머스_lv2네트워크 {
    HashSet<int> nodeSet = new HashSet<int>();
    
    void Network(int[,] computers, int length, int idx, ref int answer){
        if(nodeSet.Contains(idx)) return;
        nodeSet.Add(idx);
        for(int i=0; i<length; i++){
            if(computers[idx,i]==1 && idx!=i) {
                Network(computers, length, i ,ref answer);
            }
        }
    }
    
    public int solution(int n, int[,] computers) {
        int answer = 0;
        for(int i=0; i<n; i++){
            if(!nodeSet.Contains(i)){
              Network(computers, n, i, ref answer);
              answer++;
            }
        }
        return answer;
    }
}

//한마디로 주어진 배열로 몇 개의 그래프가 생기냐는 걸 묻는 문제.
//아마 연결이 제대로 되어있는 그래프라면 어느 위치의 노드에서 BFS, DFS를 하더라도
//그 그래프에 속한 모든 노드를 방문 할 수 있을 것이다.

//Network()함수는 특정 노드를 기준으로 거기에 속한 모든 그래프에 순회를 돌아주는
//함수이다.
//network함수는 모든 노드를 전부 방문할때까지 재귀가 계속 되며, 재귀가 끝났다면
//hashset안에는 지금껏 돌았던 노드에 대한 정보가 담겨있을 것이다.

//따라서 Network()함수는 아직 돌지 않은 노드들, 즉 이전 노드를 부모로 삼았을때
//여전히 그래프에 속하지 않아서 순회되지 못한 노드들을 기준으로 함수를 돌린다.

/*
이는 그에 대한 코드다.
         if(!nodeSet.Contains(i)){
              Network(computers, n, i, ref answer);
              answer++;
            }
*/

//그리고 순회를 돌때는 인덱스 0번부터 싹다 돌아주는데
/*
        for(int i=0; i<length; i++){
            if(computers[idx,i]==1 && idx!=i) {
                Network(computers, length, i ,ref answer);
            }
        }
*/

//그 이유는 노드 시작점에 따라서 순회 순서가 달라질 수 있기 때문에
//현재 노드와 같은 인덱스가 아니고서야 모든 노드를 다시 되짚으며 돌아본다.
//어차피         if(nodeSet.Contains(idx)) return; 얘 때문에 
//이미 둘러본 노드라면 금방 돌아가서 성능적 문제는 크게 없음.

