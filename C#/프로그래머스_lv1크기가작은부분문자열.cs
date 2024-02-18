//https://school.programmers.co.kr/learn/courses/30/lessons/147355
//프로그래머스lv1크기가 작은 부분 문자열
//2024.02.19
//30분


public class 프로그래머스lv1크기가작은부분문자열 {
    public int solution(string t, string p) {
        int answer = 0;
        int plen = p.Length;
        int tlen = t.Length;
        
        for(int i=0; i<(tlen-plen)+1; i++){
            string str = "";
            
            for(int j=i; j<(i+plen); j++)
                str+=t[j].ToString();
            
            answer+=1;
            for(int k=0; k< plen; k++){
                if(Int32.Parse(str[k].ToString()) > Int32.Parse(p[k].ToString())){
                    answer-=1;
                    break;
                }
                else if (Int32.Parse(str[k].ToString()) == Int32.Parse(p[k].ToString())) continue;   
                else  break;      
            }
        }

        return answer;
    }
}

//문자열 일부러 for문으로 잘라가면서 구현함
//근데 substring써도 큰 문제 없음
