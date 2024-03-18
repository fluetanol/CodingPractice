//https://school.programmers.co.kr/learn/courses/30/lessons/12947
//프로그래머스lv1하샤드수
//2024.03.17
//10분

using System;
public class Solution {
    public bool solution(int x) {
        string sx = x.ToString();
        int sum = 0;
        foreach(var s in sx)  sum += s-'0';
        bool answer = x % sum==0 ? true: false;
        return answer;
    }
}

//자릿수를 구하는 가장 간단한 방법 : string변환

//string을 foreach로 접근하면 char형으로 변환되기 때문에
//'0'으로 빼줘서 실제 정수 값을 만들도록 해야함.
