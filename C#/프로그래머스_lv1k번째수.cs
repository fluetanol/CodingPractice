//https://school.programmers.co.kr/learn/courses/30/lessons/12982
//프로그래머스_lv1k번째수
//2024.02.23
//30분
using System;

public class 프로그래머스_lv1k번째수
{
    public int[] solution(int[] array, int[,] commands)
    {
        int[] answer = new int[commands.Length / 3];
        int[] temparray = (int[])array.Clone();

        for (int p = 0; p < commands.Length / 3; p++)
        {
            int i = commands[p, 0] - 1;
            int j = commands[p, 1] - 1;
            int k = commands[p, 2];

            for (int q = i; q <= j; q++)
            {
                int min = temparray[q];
                int minindex = q;
                for (int r = q; r <= j; r++)
                {
                    if (min > temparray[r])
                    {
                        min = temparray[r];
                        minindex = r;
                    }
                }
                int temp = temparray[q];
                temparray[q] = min;
                temparray[minindex] = temp;
                min = 9999;
            }
            answer[p] = temparray[i + k - 1];
            temparray = (int[])array.Clone();

        }
        return answer;
    }
}

//리스트를 별도로 만들어서 i~j까지의 숫자를 담고 소팅하는 방법도 있긴 한데
//기왕이면 공간복잡도를 줄일수 있으니까 다이나믹하게 변수를 더 만들어서 
//원래 리스트에서 조절하는 방법으로 구현했다.
//참고로 내가 구현한 sort는 Selection이고
//굳이 저 방법 안쓰고도 Array.sort()써도 ㄱㅊ