//https://school.programmers.co.kr/learn/courses/30/lessons/120866
//프로그래머스_lv0안전지대
//2024-02-21
//소요시간 15분

using System;
public class 프로그래머스_lv0안전지대
{

    public void UnsafeCheck(ref int[,] board, int i, int j)
    {
        for (int k = i - 1; k < i + 2; k++)
        {
            for (int l = j - 1; l < j + 2; l++)
            {
                try
                {
                    if (board[k, l] == 1) continue;
                    board[k, l] = -1;
                }
                catch (Exception e)
                {
                    continue;
                }
            }
        }
    }


    public int solution(int[,] board)
    {
        int answer = board.Length;
        int Length = (int)Math.Sqrt(board.Length);

        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; j < Length; j++)
            {
                if (board[i, j] != 1) continue;
                UnsafeCheck(ref board, i, j);
            }
        }

        for (int i = 0; i < Length; i++)
        {
            for (int j = 0; j < Length; j++)
            {
                if (board[i, j] == 1 || board[i, j] == -1)
                    answer -= 1;
            }
        }

        return answer;
    }
}

//lv0 주제에 골때리는 문제
//이 문제는 성능적 최적화를 충분히 더 할 수 있지만, 하든 말든 중첩 for문으로 인한 코드의 더러움은 해소하기 어렵다.
//어쩔 수 없이 지뢰 인접 불안전지대를 표시하는 부분은 별도의 함수로 표현하였다.
//참고로 위 방식은 안정성을 보장한 코드로 
//불안전지대를 모두 표시한 뒤, 다시 배열을 순회하여 보면서 불안전지대+지뢰인 칸을 전체 배열 길이에서 빼주는 방식으로 답을 구했다.
//Exception은 지뢰가 확인된 칸이 배열의 끝쪽에 위치하여 index exception이 발생하는 경우를 대비한 것.

//저 방법 말고도 지뢰가 있는 곳을 전부 찾고 좌표 위치관계를 이용하여 수학적으로 풀수도 있을듯.