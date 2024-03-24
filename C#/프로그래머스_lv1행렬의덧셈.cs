//https://school.programmers.co.kr/learn/courses/30/lessons/12950
//프로그래머스lv1행렬의 덧셈
//2024.03.17
//4분


using System;

public class 프로그래머스lv1행렬의 덧셈 {
    public int[,] solution(int[,] arr1, int[,] arr2) {
        int[,] answer = arr1;
        int r = arr1.GetLength(0);
        int c = arr1.Length / r;

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                answer[i,j] = arr1[i,j] + arr2[i,j];
            }
        }
        
        return answer;
    }
}

//저런 고정크기 2차원 배열에서 행과 열 각각의 갯수를 구하는 방법을 몰랐는데
//GetLength(몇번째 행인지) 를 쓰면 구할 수 있다는 걸 첨 알았다....