//https://school.programmers.co.kr/learn/courses/30/lessons/68935
//프로그래머스_lv1_3진법뒤집기
//2024.03.27
//15분

using System;
using System.Text;
using System.Linq;
public class 프로그래머스_lv1_3진법뒤집기 {
    public int solution(int n) {
        int answer = 0;
        StringBuilder strbuilder = new StringBuilder();
        while(true){
            if(n<1) break;
            strbuilder.Append(n%3);
            n = n / 3;
        }
        string rs = new string(strbuilder.ToString().Reverse().ToArray());
        for(int i=0; i<rs.Length; i++){
            answer += (rs[i]-'0') * (int)Math.Pow(3,i);
        }
        return answer;
    }
}

//오늘의 팁 : 반복문 안에서 문자 붙히기를 많이 하게 될 거 같으면
//stringbuilder를 사용하는 게 더 좋은 성능을 보인다
//문자열의 +연산은 사실상 새로운 문자열 객체를 계속 할당 해주는 거나 다름없어서
//가비지컬렉션의 오버헤드가 발생하기 때문.

//한편 문자열 뒤집기에 대한 코드는 외워두는게 편할듯.
//  string rs = new string(strbuilder.ToString().Reverse().ToArray());