//https://school.programmers.co.kr/learn/courses/30/lessons/42883
//프로그래머스_lv2큰수만들기
//2024.03.22
//3시간

using System;

public class 프로그래머스_lv2큰수만들기 {
    public string solution(string number, int k) {
        string answer = "";
        
        int valid = number.Length - k;
        int max = -1;
        int maxidx = -1;
        int sidx = -1;
        
        while(true){
            if(sidx >= number.Length-valid-1) break;
            if(valid==0) break;
            
            for(int i=sidx+1; i<=number.Length-valid; i++){
                if(max < number[i] - '0'){
                    max = number[i] - '0';
                    maxidx = i;
                }
            }
            answer += number[maxidx];
            sidx = maxidx;
            valid--;
            max = -1;
        }
        
        if(valid!=0)
        answer+= number.Substring(sidx+1, number.Length-sidx-1);
     return answer;
    }
}

//우진이 아이디어로 풀린 그리디 문제

//예를 들어
//197848655 , k=4라고 하자.
//우선 당연히 그리디하게 가장 큰 수 순서대로 고르는 방식으로 문제를 풀고 싶을건데, 
//전체 숫자에서 큰 수 순서대로 고르는 건 다른 반례에서 낭패를 본다.

//일단 이 문제는 이런 규칙이 있다.
//가장 큰 자릿 수가 k번째라면
//위 예시는 948655가 확정 정답이다. 전체에서 4개의 수를 버려야한다면 전체 자릿수에서 k를 뺀 만큼의
//수, 즉 n-k개 만큼의 수를 골라야 하는데, 위 예시는 6개를 골라야 하므로
//만약 가장 자릿수가 커서 살려둬야 하는 숫자가 k번째면 그 아래에 있는 숫자까지 확정적으로 정답이 되는 것이다.

//이 규칙을 활용하면

//1. 가장 큰 자릿 수를 선정하기 위해 처음에는 0번째부터 k번째 자리까지 가장 큰 수가 있는
//자릿 수를 찾아낸다
//ex) 19784 중 가장 큰 수 9 선정

//2. 1개를 골라냈으므로, 골라야 하는 수는 n-k-1, 즉 5개가 남았다. (n은 전체 자릿수)
//9 아래에 있는 숫자들 7848655중 5개를 골라야 하는데 4를 고르면 8655까지 확정이므로
//이를 고려하여 784까지만 8이 그 다음 큰 숫자 확정.

//3. m개를 골라냈다면, 앞으로 골라야 하는 수는 n-k-m.
//최대한 대소 비교를 하여 그 안에서 가장 큰 수를 계속 고르는 방식을 선택해야하므로
//이전의 최댓값이 존재한 인덱스부터 n-(n-k-m)번째 인덱스까지의 가장 큰 수를 골라준다.
//48655, 4개 골라야 하므로 8을 고름, 9->8->8

//4. 3번 작업을 반복하다보면 종단점이 두가지 케이스로 나뉜다
//  1) 앞으로 골라내야할 숫자의 갯수와 내가 최댓값을 체크하기 위한 범위가 같은 경우
//  2) 그냥 더 이상 골라내야 할 숫자가 없어서 추가 체크할 이유가 없어진 경우

//1)의 경우는 위의 케이스와 같은데, 
//남아있는 655에서 앞으로 골라야 할 숫자는 3개이고 최댓값을 체크하기 위한 범위도 655, 즉 3개이므로
//655가 한번에 확정난다.

//2)의 경우는 number = 798, k=2같은 특이케이스인데
//첫 시도에서 9가 최댓값으로 확정나고 더 이상 찾아 볼 숫자가 없으므로 맨 뒷자리인 8을 볼 필요가 없다.

//1)의 케이스인 경우 남아있는 숫자들을 지금껏 2,3번작업을 통해 얻은 문자열에 substring을 더하는 방식으로
//break해서 마무리를 지으면 되고
//2)의 경우 그냥 아무 작업 없이 break하고 종료시키면 된다.


//그리디 알고리즘이라는 게 아무튼간에 욕심을 부려서 가장 최선이라고 생각되는 선택지만 고르는 방식인데
//아무렇게나 욕심을 부릴게 아니라 문제를 보고 어떤 규칙을 찾고, 그 규칙에 맞게 최선의 선택지를
//무조건 고르는 방식으로 풀어야 겠다는 생각이 들었다...

//다시 말하면 어떤 규칙이 있는지 파훼를 못하면 풀기도 힘들어진다는 걸 염두해둬야한다...





