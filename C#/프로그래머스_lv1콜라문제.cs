//https://school.programmers.co.kr/learn/courses/30/lessons/132267
//프로그래머스_lv1콜라문제
//2024.03.14
//20분

using System;

public class 프로그래머스_lv1콜라문제
{
    public int solution(int a, int b, int n)
    {
        int answer = 0;
        while (true)
        {
            int r = n % a;
            n = (n - r) / a;
            answer += n * b;
            n = b * n + r;
            if (n < a) break;
        }
        return answer;
    }
}


//수수께끼 문제 참 짜증남
//로직 설명

//1. n이 a로 나누어 떨어지는지 확인한다. 나머지가 있다면 해당 나머지 갯수로는
//b개의 콜라를 추가로 못받으니 임시적으로 n에서 제외시켜준다. (n-a)

//2. n을 a로 나눠준다. a개의 병마다 b개의 콜라를 받을 수 있으니,
//n을 a로 몇번 나눌 수 있는지 알아야 b개의 콜라를 추가로 받는 지도 알 수 있다.

//3. k번 나누어진다면 일단 k*b개는 추가로 받을 수 있다. (answer += n*b)

//4. 이제 2~3에서 구한 b * k개의 콜라와 1에서 구한 계산에서 뺀 나머지 콜라를 복구시켜주고
//다시 1~3과 같은 작업을 반복한다.   (n = b * n + r;)

//5. 이 작업은 n이 a보다 작아지며 나머지 콜라밖에 없어서 더이상 b개의 추가 콜라를
//못받을때까지 반복한다 (if (n < a) break;)
