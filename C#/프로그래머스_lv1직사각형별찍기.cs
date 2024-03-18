//https://school.programmers.co.kr/learn/courses/30/lessons/12969
//프로그래머스lv1직사각형별찍기
//2024.03.17
//소요시간5분


using System;

public class 직사각형별찍기
{
    public static void Main()
    {
        String[] s;
        s = Console.ReadLine().Split(' ');
        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);
        for(int i=0; i<b; i++){
            for(int j=0; j<a; j++)Console.Write("*");
            Console.WriteLine();
        }
    }
}

//위에같이 푸는게 가장 무난한 방법


public class 직사각형별찍기2
{
    public static void Main()
    {
        String[] s;
        Console.Clear();
        s = Console.ReadLine().Split(' ');

        int a = Int32.Parse(s[0]);
        int b = Int32.Parse(s[1]);

        string temp = "";

        for (int i=0; i<a; i++)  { temp += "*"; }
        for (int i=0; i<b; i++)   { Console.WriteLine("{0}",temp); }
    }
}
//이렇게 푸는 게 실제 속도 성능에선 훨씬 더 좋음
//Console.WriteLine같은 출력 함수의 성능이 썩 좋진 않아서...
