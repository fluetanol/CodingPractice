using System;
class ProgramTest{
    private static void Main(){
        int[] answer = new int[] { 5 };
        for (int i = 0; i < 5; i++)
        {
            answer.Append(i);
         
        }
        Console.WriteLine(answer);
    
    }
}