//https://school.programmers.co.kr/learn/courses/30/lessons/132267
//프로그래머스_lv1콜라츠추측
//2024.03.17
//0740


public class 콜라츠추측 {
    public int solution(int num) {
        int answer = -1;
        int iterate = 0;
        while(iterate!=500){
            if(num == 1) {
                answer = iterate;
                break;
            }
            if(num%2 == 0) num/=2;
            else if(num%2 == 1) num=num*3+1;
            iterate+=1;
        }
        return answer;
    }
}
//문제에 제시된 그대로 구현해주면 됨.