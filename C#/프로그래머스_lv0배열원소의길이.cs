//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/02/18
public class 프로그래머스_lv0배열원소의길이
{
    public int[] solution(string[] strlist)
    {
        int[] answer = new int[strlist.Length];
        for (int i = 0; i < answer.Length; i++) answer[i] = strlist[i].Length;
        return answer;
    }
}

//c# 고정 배열은 다른 언어와 마찬가지로 미리 칸수를 할당해주고 시작해야함
//거슬린다면 list같은 동적크기배열 쓰는걸 추천