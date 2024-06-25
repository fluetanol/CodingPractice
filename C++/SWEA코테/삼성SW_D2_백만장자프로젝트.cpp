// https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5LrsUaDxcDFAXc&categoryId=AV5LrsUaDxcDFAXc&categoryType=CODE&problemTitle=&orderBy=FIRST_REG_DATETIME&selectCodeLang=ALL&select-1=&pageSize=10&pageIndex=1
// 삼성아카데미d2백만장자프로젝트
// 24/04/19
// 05/14 16:40 힌트 + 자력으로 풀음...

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
        int n, k;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        long long price = 0;
        int idx = 0;
        while (idx < v.size())
        {
            int max = -1;
            int maxidx = -1;
            long long temp = 0;
            for (int i = idx; i < v.size(); i++)
            {
                temp -= v[i];
                if (max < v[i])
                {
                    max = v[i];
                    maxidx = i;
                    price += temp;
                    temp = 0;
                }
            }

            price += (maxidx + 1 - idx) * v[maxidx];
            idx = maxidx + 1;
        }

        cout << "#" << test_case << " " << price << endl;
    }
    return 0;
}


//이게 왜 d2냐... 최소 d3중간난이도~d4쉬운 난이도 사이에 속해야할듯

/*
문제의 사용 알고리즘은 그리디 알고리즘이다...
입력 n이 너무 크기 때문에 (백만) 완전탐색으로는 시간내에 못푸는 문제.
자꾸 DFS로 풀거나 HASHMAP을 이용한 최적화 작업으로 풀어보려다가 헛발쳐서 푸는데에 오래걸렸다...


일단 최대 금액을 벌기 위해선 계속 사재기를 하다가 최대로 비싼 가격인 타이밍에 파는게 좋다.
예를 들어

1 1 4 7 3 이라고 하면 3일동안 1,1,4원의 물품을 전부 사두다가, 4일때 최대치일때 팔아버리면 큰 이익을 얻을 수 있다.

즉, 저점매수 계속 하다가, 모든 날들 중 최대 고점을 찍을 때 마다 팔아두면 이득이 된다는 것...

주식하듯이 하면 되는데, 주식과 다른 점은 주식은 중간 최대치인지 최고점일지 모른다는 거고 이 문제는 모든 날에 대한
가격이 예측 가능하기 때문에 전체의 최대치가 언제인지 알 수 있다는 것이다.

그럼 아래 예시를 보자

1 1 7 6 5 8 3 4 4 1 7

이런 예시가 있다고 하면, 최대치는 8이므로 1,1,7,6,5의 가격의 물품들을 사재기 하고 8원으로 전부 팔아버리면 된다.
그럼 나머지 3,4,4,1,7은 어떻게 해야할까?

이 또한 마찬가지로 남아있는 날들 중 최대치를 찾아서 그때 팔아버리면 된다. 즉 3,4,4,1원의 가격 물품들을 사고 7원에 팔아버릴
생각을 하면 된다는 것

정말 미래 예지 가능한 주식을 한다 생각하고 언제 매매하면 최대 이익을 얻을지를 생각하면서 풀면 된다...


예외?)
만약

1 1 1 1 1

이렇게 모든 날의 가격이 같은 경우엔 어떻게 할까?
정답은 사든 말든 아무 문제 없다는 것이다.
주식 그래프로 따지면 상승도 하강도 안해서 처음 매수한 돈 그대로 남아있는 상태이다.



그런데 사실 실제 구현은 좀더 까다로운데,
말이 최댓값을 구하면 되요 인거지 실제로 최댓값을 구하려면 배열 전체를 한번 훑어봐야 하기 때문이다
그럼 최댓값을 구하는 작업 한번, 최댓값 위치 까지 더하고 빼는 과정 한번을 한다면 그건 그것대로 오버헤드가 생긴다
즉, 최댓값을 구하면서 값의 업데이트를 한번에 이루게 하는 게 좋다.



            for (int i = idx; i < v.size(); i++)
            {
                temp -= v[i];
                if (max < v[i])
                {
                    max = v[i];
                    maxidx = i;
                    price += temp;
                    temp = 0;
                }
            }


            price += (maxidx + 1 - idx) * v[maxidx];
            idx = maxidx + 1;


우리는 최댓값이 있는 날의 전날까지 사재기를 해줘야 한다.
다시 말하면 최댓값이 있기 전까진 계속 사주는 척 하는 연산을 하다가, (temp -= v[i];)
진짜 최댓값이 발견되면  ->  if (max < v[i])
그때서야 지금까지 사재기 한 척 한 물품들을 진짜 사들여버린다. price += temp;

            price += (maxidx + 1 - idx) * v[maxidx];
이후 판매 할 날의 가격 * 사들인 물품 수량만큼 팔아버리면 되며
이후 남은 날들 중에서의 다음 최댓값을 찾아가면 된다  ( idx = maxidx + 1;)


알고리즘을 생각해내는 것도 익숙하지 않으면 껄끄러운데
그 안에서도 또 최적화 작업까지 해야해서 더 껄끄러웠던 자칭 D2문제였다...

*/