// https://school.programmers.co.kr/learn/courses/30/lessons/12931
// 프로그래머스_lv1자릿수더하기
// 24/06/14
// 1분

#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;

    string k = to_string(n);

    for (auto i : k){
        answer += (i - '0');
    }

    return answer;
}

//오랜만에 해서 다시 몸풀기용으로 풀어본 문제