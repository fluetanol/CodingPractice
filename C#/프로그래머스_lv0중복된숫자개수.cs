//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음 
// 2024/02/18
public class 프로그래머스_lv0중복된숫자개수
{
    public int solution(int[] array, int n)
    {
        int answer = 0;
        foreach (var i in array) if (i == n) answer += 1;
        return answer;
    }
}