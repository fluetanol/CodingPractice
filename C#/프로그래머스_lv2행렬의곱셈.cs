//https://school.programmers.co.kr/learn/courses/30/lessons/43165
//프로그래머스_lv2행렬의곱셈
//2024.04.04
//15분

using System;

public class 프로그래머스_lv2행렬의곱셈 {
    public int[][] solution(int[,] arr1, int[,] arr2) {
        int row = arr1.GetLength(0);
        int col = arr1.Length/row;
        int row2 = arr2.Length/arr2.GetLength(0);
        
        int[][] answer = new int[row][];
        for(int i=0; i<row; i++) 
            answer[i] = new int[row2];

        for(int i=0; i<row; i++){
            for(int k=0; k<row2; k++){
                int ans = 0;
                for(int j=0; j<col; j++){
                    ans += arr1[i,j] * arr2[j,k];
                }
                answer[i][k] = ans;
            }
        }
        return answer;
    }
}

//어렵진 않은데 행렬 곱셈의 특성을 잘 모르면 좀 짜증나는 문제


//1. A*B에서 A의 행 갯수를 r, A의 열 갯수를 c라고 하면
// A의 인덱스 접근은 A[r,c];
// 한편 B의 행 갯수는 행렬 곱을 위해 A의 열갯수와 동일함.
// 그리고 B의 열 갯수를 c2라고 한다면 인덱스 접근은 B[c,c2];

//2. 행렬 곱을 한 결과의 행렬 크기는 A의 행 크기 * B의 열 크기

//참고로 이거보다 더 좋은 방식의 코드는 병렬처리 시키는 것 말곤 없음.
