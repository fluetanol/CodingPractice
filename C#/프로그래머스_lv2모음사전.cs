//https://school.programmers.co.kr/learn/courses/30/lessons/84512
//프로그래머스_lv2모음사전
//2024.04.07
//30분

using System;

public class 프로그래머스_lv2모음사전
{
    bool Search(string word, string s, char[] cs, int depth, ref int count){
        if(depth == 5) return false;
        
        bool isFind = false;
        for(int i=0; i<5; i++){
            string temp = s;
            temp +=cs[i];
            count++;
            if(temp == word) return true;
            isFind = Search(word, temp, cs, depth+1, ref count);
            if(isFind)  return true;
        }
        return isFind;
    }
    
    public int solution(string word) {
        int answer = 0;
        char[] cs = new char[5]{'A','E','I','O','U'};
        Search(word, "",cs,0, ref answer);
        return answer;
    }
}

//조합 완전 탐색을 풀 줄 알면 진짜 어려울게 없는 문제.
//lv2 의상 문제 다시 보고 오면 참고가 잘 될 것.
//이런 완전 탐색 문제는 보통 bfs, dfs로 푸는게 빨리 풀리는데
//언제 종단점으로 할지, 어느 타이밍에 recursion을 할지
//두개에 대한 감만 잡히면 어지간한건 다 풀만 해지는 듯