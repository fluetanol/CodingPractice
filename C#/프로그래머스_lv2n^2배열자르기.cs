//https://school.programmers.co.kr/learn/courses/30/lessons/87390
//프로그래머스_lv2n^2배열자르기
//2024.03.22
//30분


using System;
using System.Collections.Generic;
public class 프로그래머스_lv2n^2배열자르기 {
    public int[] solution(int n, long left, long right) {
        int[] answer = new int[] {};
        List<int> l = new List<int>();  
        for(long idx = left; idx<=right; idx ++){
            int rotate = (int)(idx / n) + 1;
            int order = (int)(idx % n) + 1;
            int num = rotate >= order ? rotate : rotate + (order - rotate);
            l.Add(num);
        }
        answer = l.ToArray();
        return answer;
    }
}

//일단 이 문제는 보이는 그대로 박치기 해서 풀면 안된다...
//규칙을 수학적으로 찾아서 푸는 문제다.


//1. 가장 느리지만 쉬운 방법
//2차원 배열에 주어진 문제 조건대로 숫자를 넣은 후, 행을 하나하나 나열시켜서 left~right를 체크하는 방법.
//제한사항이 n = 10^7인바, O(n^2)이면 무시무시한 성능이 나와서 시간 탈락

//2. 규칙을 살짝 찾아낸 방법
//1차원 배열에 주어진 조건대로 넣었을 때 일정한 규칙이 생긴다는 걸 금방 발견할 수 있다.
/*ex) 3
  1 2 3    -> 123 223 333
  2 2 3
  3 3 3

  ex 5
  1 2 3 4 5  -> 12345 22345 33345 44445 55555
  2 2 3 4 5
  3 3 3 4 5
  4 4 4 4 5
  5 5 5 5 5
*/

//즉, 1행은 12345, 2행은 22345... k행은 k가 k번 있고 k+1, k+2...n까지 나열된다.
//이 규칙대로 1차원 배열에 한번에 나열시켜서 풀어도...
//사실 배열의 길이는 O(n^2)이기 때문에 1번보다 빠르긴 해도 여전히 느리다.


//3. 임의의 인덱스 k에서의 값을 수학적으로 예측하는 방법
//결론부터 말하면 이 방법이 제일 빠르다
//우리가 구해야 하는건 전체 n^2개의 수가 아니라 사실 left~right인덱스 사이의 숫자들만 예측하면 된다.
//이걸 할 줄 안다면 성능이 O(right-left)가 되는데, n과 left, right의 관계를 생각해보면 right-left<n임이
//자명하기 때문에 O(n)보다 더 낮은 성능으로 풀 수 있다.

//임의의 인덱스값 k가 주어진다고 하고, 보기 편하게 인덱스값은 1부터 시작한다고 치자
//위에서 본 규칙을 보면 알 수 있겠지만 저 규칙은 n개 단위로 주기를 이룬다.
//k값이 몇번째 주기인지 알고 싶다면 k/n을 하면 된다.
//k값이 그 주기 안의 몇번째 인덱스인지 알고 싶다면 k%n을 하면 된다.

//k/n번째 주기를 r이라고 하면 인덱스 k는 곧 이차원 배열의 r번째 행의 인덱스라는 건데,
//위 규칙에 따라 r이 r번 있다는 것도 예측 할 수 있다.
//이에 따라 우린 이런 이지선다를 할 수 있다

// 1. k%n이 r보다 같거나 작으면 r의 반복안에 있음
// 2. k%n이 r보다 크다면 r의 반복에서 벗어나서 1씩 더해지는 중임

//