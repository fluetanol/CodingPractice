// 문제번호 : 1057번
// 토너먼트
// 푼 시간 : 30분
// 알고리즘 분류 : 수학, 분할정복

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    int a, b;
    cin >> n >> a >> b;

    int ateam = (a + 1) / 2;
    int bteam = (b + 1) / 2;
    int round = 1;

    while (true)
    {
        if (ateam == bteam)
            break;
        ateam = (ateam + 1) / 2;
        bteam = (bteam + 1) / 2;
        round++;
    }

    cout << round << endl;
}


/*
    아래에서 위로 어떤 라운드에 a와 b가 매칭될지를 a와 b각각이 속한 팀을 추적한다.
    같은 team에 속하면 그 라운드에서 만나게 된다는 뜻.

    팀 구하는 법은 엄청 간단한데,
    
    어차피 두명씩 짝지어져 한팀이 된다는 점을 이용해보면

    1,2는 1팀 3,4는 2팀....
    이렇게 나아간다는 걸 알 수 있다.
    이를 공식화 시켜보면, 어떤 숫자 k에 대해
    
    round(k/2) 가 딱 k의 팀이 된다.

    ex) 1/2 =0.5, round(0.5)=1...

    그렇다면 라운드가 n만큼 지나갔다면

    round(k/2^n) 가 딱 k의 팀이 되며,
    k를 a, b로만 바꿔서 둘이 같아지는 지점을 찾기만 하면 된다.
    
    성능은 O(logN)
    끝!
*/