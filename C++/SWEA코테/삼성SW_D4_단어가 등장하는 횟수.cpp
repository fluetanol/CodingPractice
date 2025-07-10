#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    long long p = 67;
    long long mod = 1000000007;

    int tc = 0;
    cin >> tc;

    for (int test_case = 1; test_case <= tc; ++test_case)
    {
        string b;
        string s;
        cin >> s >> b;

        int blen = b.length();
        long long bhash = 0;
        vector<long long> computedPow(blen);

        computedPow[blen - 1] = 1;
        for (int i = blen - 2; i >= 0; i--)
        {
            computedPow[i] = (computedPow[i + 1] * p) % mod;
        }

        for (int i = 0; i < blen; i++)
        {
            bhash += (b[i] * computedPow[i]) % mod;
        }
        bhash %= mod;
        int slen = s.length();
        long long shash = 0;
        int count = 0;

        for (int i = 0; i <= slen - blen; i++)
        {
            if (i == 0)
            {
                for (int i = 0; i < blen; i++)
                {
                    shash += (s[i] * computedPow[i]) % mod;
                }
                shash %= mod;
            }
            else
            {
                shash = (shash - (s[i - 1] * computedPow[0]) % mod + mod) % mod;
                shash = (shash * p) % mod;
                shash = (shash + s[i + blen - 1]) % mod;
            }

            if (shash == bhash)
            {
                count++;
            }
        }

        cout << "#" << test_case << " " << count << "\n";
    }
}


// 문자열 검색 문제인데 input 범위가 크기 때문에 최적화된 고급 알고리즘을 써야한다.

// 라빈 카프 알고리즘의 롤링 해쉬 기법을 이용해서 풀었다
/*
    롤링 해쉬 
    슬라이드 윈도우를 이용한 해쉬 연산 기법으로 식은 이런식으로 세운다.

    p^k-1 * s[0] + p^k-2 * s[1] + ... + p^0 * s[k-1] (mod m)
    여기서 p는 소수, m은 모듈러 연산을 위한 소수이다. 
*/


/*
    나머지를 취하는 이유는 오버플로우 방지도 있고 값을 안정적으로 만들기 위함도 있다.
    
    참고로 해쉬 값 비교이므로 해쉬 충돌이 일어날 확률도 있는데, 보통은 이중 해쉬를 사용하면 확률을 급격히 낮출 수 있다.


    다만, 진짜 재수가 없으면 그래도 해쉬 충돌로 틀리는 케이스가 생길 수 있고, 일부 문자열 탐색 문제의 경우
    일부러 라빈 - 카프 알고리즘을 저격한 테스트 케이스를 내놓는 경우도 있다고 하니 완전한 안정성있는 알고리즘을 선호한다면
    KMP로 푸는 걸 추천한다.

    그래도 라빈 카프가 이해하기 쉽고 구현도 간단하다는 점에서 굉장히 매력있는 알고리즘이긴 함.

    참고로 시간복잡도는 O(n+m) (+m 이 붙는 이유는 처음에 m의 길이만큼 롤링 해싱을 해야하기 때문)
*/

/*
    모듈러 연산 주의점

   - 음수일 수 있는 케이스 주의해야함
    (위 코드의 경우 shash = (shash - (s[i - 1] * computedPow[0])) * p; 에서 shash가 나머지 연산된 값이여서
    s[i - 1] * computedPow[0]이 shash보다 크면 음수가 될 여지가 있음
    그래서
  
    shash = (shash - (s[i - 1] * computedPow[0]) % mod + mod) % mod;

    로, s[i - 1] * computedPow[0]에도 mod연산을 취하고, 전체 연산값이 절대 음수가 될 수 없도록 +mod를 취해서 나머지 평행이동 연산을 취한 것.
    뺼셈 있는 부분에 나머지 연산이 담긴 변수가 있다면 음수 가능성을 일단 의심해야한다.
*/