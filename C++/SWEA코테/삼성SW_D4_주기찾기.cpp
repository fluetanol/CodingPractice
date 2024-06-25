// https :  swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d4주기찾기
// 24/05/03
// 1시간

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        long long arr[4];
        cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
        vector<int> um(arr[3]);

        int idx = 2;
        int a0 = arr[0];
        um[arr[0]] = 1;

        for (int i = 0; i < arr[3]; i++)
        {
            long long next = (arr[1] * a0 + arr[2]) % arr[3];
            a0 = next;
            if (um[next] <= 0)
            {
                um[next] = idx;
                a0 = next;
            }
            else
            {
                cout << "#" << test_case << " " << idx - um[next] << endl;
                break;
            }
            idx++;
        }
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//점화식 문제지만 dp라고 보기엔 값의 재활용 빈도가 단 한번뿐이라서 dp라고 보기는 애매하다
//결론부터 말하면 주기가 돌았는지 아닌지 확인하기 위해, 이전에 나온 숫자가 다시 한번 나왔는지만 확인해보면 되는 문제다.

//여기서 주의할 점은, 이 문제의 시간 특성상 hashmap에 저장하는건 약간의 오버헤드가 존재하는지 시간초과가 났었고
//배열에 저장해야 진정한 O(1)의 빠른 검색성능으로 (해쉬맵은 해쉬값을 찾기 위한 연산이나 버킷에 담기는 경우에 추가적인 비용이 들음) 통과가 되었다

//그런데 좀 이상한 점은 int*로 동적할당 시키면 배열할당을 어마어마하게 해야해서
//테스트케이스마다 그냥 동적할당을 때리면 할당공간의 초과로 인해 segment fault가 뜨는 듯 했는데
//그래서 매 케이스마다 delete[]를 하면 이상하게 다음 테스트케이스에서 할당을 받을때 쓰레기 공간을 할당 받는 현상이 있었다...
//이 때문에 그럴 위험이 더 적은 vector로 문제를 풀어보니 해결은 되었는데
//왜 delete에서 그런 문제가 터졌는지는 우진이한테 물어봐야겠다...
//여러모로 구현이 어렵진 않으나 메모이제이션 할 자료구조에 따라 미묘하게 성능차이가 나서 타이트한 최적화가 필요했던 문제.
//+ 내 c++이해도 부족으로 많이 절었던 문제였다...