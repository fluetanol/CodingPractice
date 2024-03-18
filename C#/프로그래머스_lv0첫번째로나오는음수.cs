//lv0 언어 적응 + 머리 풀기 용 너무 쉬운 문제는 별다른 설명없이 넘어가겠음
// 2024/03/17

using System;
public class 첫번째로나오는음수 {
    public int solution(int[] num_list) {
        int answer = -1;
        for(int i=0; i<num_list.Length; i++){
            if(num_list[i]<0){
                answer = i;
                break;
            }
        }
        return answer;
    }
}