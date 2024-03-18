//https://school.programmers.co.kr/learn/courses/30/lessons/12947
//프로그래머스lv1핸드폰번호가리기
//2024.03.17
//4분

using System;

public class 핸드폰번호가리기 {
    public string solution(string phone_number) {
        string answer = "";
        int len = phone_number.Length;
        for(int i=0; i<len-4; i++) answer+="*";
        answer += phone_number.Substring(len-4,4);
        return answer;
    }
}

//substring은 문자열 처리에 아주 유용한 함수
//substring(시작인덱스, 시작점으로부터 얼마나 갈건지);
//ex) substring(2,4) -> 2번째 문자부터 2+4번째 문자까지