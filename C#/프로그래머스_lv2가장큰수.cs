//https://school.programmers.co.kr/learn/courses/30/lessons/42746#
//프로그래머스_lv2가장큰수
//2024.03.19
//

//첫번째 풀이
using System;
using System.Collections.Generic;

public class 프로그래머스_lv2가장큰수 {
    public string solution(int[] numbers) {
        string answer = "";
        Dictionary<string, string> dicnum = new Dictionary<string, string>();
        foreach(var k in numbers){
            string sn = k.ToString();
            if(dicnum.ContainsKey(sn)) dicnum[sn]+=sn;
            else dicnum[sn] = sn;
        }
        for(int i=999; i>=100; i--){
            string sn = i.ToString();
            string sten = sn.Substring(0,2);
            string sone = sn.Substring(0,1);
            
            //ex1 케이스
            if(sn[0]<sn[1] && sn[0] == sn[2] && dicnum.ContainsKey(sten)) answer += dicnum[sten];
             if(dicnum.ContainsKey(sn)) answer+=dicnum[sn];    

            //ex2 케이스
            if(sn[0] == sn[1] && sn[1] == sn[2]){
             if(dicnum.ContainsKey(sten))    answer += dicnum[sten];  
              if(dicnum.ContainsKey(sone))    answer += dicnum[sone];      
            }

            //ex3 케이스
            else if(sn[0]>sn[1] && sn[0] == sn[2] && dicnum.ContainsKey(sten) )  answer += dicnum[sten]; 
            
            //예외 케이스1 : 1000은 100보다 더 약한 가치의 숫자
            else if(i == 100 && dicnum.ContainsKey("1000"))    answer += dicnum["1000"];
        }
        
        //예외 케이스2 : 0은 가장 낮은 가치의 숫자
        if(dicnum.ContainsKey("0")) {
            answer+=dicnum["0"];
            //예외 케이스3 : 모든 수가 0인 경우
             if(answer == dicnum["0"]) answer ="0";
        }
        return answer;
    }
}

//가장 큰 수를 찾으려면 아무래도 가장 큰 숫자부터 나열해야 하는 거 아닌가? 라는 간단한 생각에서 시작했는데
//특수하게도 문자열 형식으로 나열이 되어야 하기 때문에 사실상 사전순 정렬을 해야한다.
//그럼 이런 규칙이 생긴다

/*
Ex1)
579 578 577 576 57 575 574 ...
[576,57]
57657 > 57576
[575,57]
57557 < 57575

이렇듯 앞 두자리가 같고, 십의 자리수가 백의 자리수보다 큰데 일의 자리 수가 백의 자리수와 같아지는 순간의 규칙


Ex2)
547 546 545 54 544 543 542 541 ...
[545,54]
54554 > 54545
[54,544]
54544 > 54454

이렇듯 앞 두자리가 같고, 십의 자리수가 백의 자리수보다 작은데 일의 자리수가 백의 자리수보다 작아지는 순간의 규칙


Ex3)
559 558 557 556 555 55 5 554 553 552 551

이렇듯 세자리가 모두 같아지는 순간의 규칙 (555,55,5 모두 같은 가치임)


이런 규칙에 맞춰서 제한 조건이 0~1000까지이므로
999~100까지 모든 숫자를 내림차순으로 훑어보고, 딕셔너리에 해당값이 존재한다면 
answer에 문자열을 추가해주는 방식이다.

이 방식의 단점을 알아보자
1) Input 값의 범위가 훨씬 커지면 성능이 위험해짐
2) 저 규칙을 찾는 게 쉬운일이 아니임
3) 코드가 직관적이지 않음

물론 input value의 분포에 따른 최적화를 거친다면 더 손볼만한 알고리즘이긴 하지만
코드 가독성과 성능의 밸런스를 생각해보려고 한다면 
가독성도 떨어지고 범용성도 떨어지는 코드같다...
다만 문제만을 위해 쓴 코드라 하면 성능은 가장 좋음.
*/


using System;
using System.Collections.Generic;

public class 프로그래머스_lv2가장큰수2 {
    public string solution(int[] numbers) {
        string answer = "";
        
        Array.Sort(numbers, (a,b) => {
                string sa = a.ToString();
                string sb = b.ToString();
                sa = (sa + sa + sa + sa).Substring(0,4);
                sb = (sb + sb + sb + sb).Substring(0,4); 
                int aa = int.Parse(sa);
                int bb = int.Parse(sb);
            
                if(aa>bb) return -1;
                else return 1;
            }      
        );
        
        string[] snums = Array.ConvertAll(numbers, x=>x.ToString());
        answer = string.Join("", snums);
        if(answer[0] == '0') answer ="0";
        
        
        return answer;
    }
}

//가독성 좋고 범용성 좋은 코드, 하지만 성능이 떨어진다.
//모든 숫자를 동일한 크기의 문자열로 바꿔주고 그 상태로 정렬을 하면 되는데, 예를 들면 다음과 같다

//[5,57,467]
//총 네 번씩 문자를 반복시키면
//[5555, 57575757 ,467467467467]
//이 중 의미 있는 문자열은 0번째 부터 네번째 문자까지이므로
//[5555,5757,4674]
//이 상태로 실제 숫자 대소비교를 하여 내림차순 해준다. 그러면
//[5757,5555,4674]
//다시 원래 숫자로 되돌리면
//[57,5,467]
//이 순서대로 문자열을 이어붙히면 정답이 된다.
//575467


//[545,54]와 같은 위의 특이 케이스도 한번 봐보자
//1. [545545545545,54545454]
//2. [5455,5454]
//3. 5455>5454 이므로 현상유지
//4. [545, 54]
//5. 54554가 정답

//문자열을 세번이 아니라 굳이 네번 반복하는 이유는 이런 케이스 때문이다.

//[5,51,515]
//555, 515151, 515515515
//여기서 최대 길이가 3이기 때문에 세번째 문자까지만 클리핑시키면
//555, 515, 515
//이와 같이 51과 515의 가치비교가 안되므로 네번째 자리까지 들여다보며 가치를 비교해야한다. 그러면
//5151 < 5155
//가 명확해지므로 515가 51보다 더 가치 높은 숫자임을 알 수 있다.

//이 방식의 단점을 또 알아보자
//1. Array.sort라는 정렬작업의 오버헤드
//2. Tostring, ParseInt하는 오버헤드
//3. answer를 만들기 위한 스트링 붙히기의 오버헤드
//특히 3번작업이 진짜 상당한 오버헤드여서 인터넷을 뒤적거려봤는데, join함수가 문자열 배열을
//한번에 하나의 문자열로 만들어준다고 해서 써봤더니, 그 성능이 어마어마하게 좋았다.
//앞으로 for문 돌려서 문자열 붙히지 말고 join함수를 요긴하게 쓰자...!
