#include <iostream>
#include <sstream>

using namespace std;

/*

    그냥 10^n 꼴은 자릿수가 n이라면, n-1개의 M으로 가득 채우면 된다
    EX) 10^5 = MMMMMM

    반면 5 * 10^n 꼴은 마지막에만 K를 붙혀주면 된다.
    5 * 10^5 = MMMMMK

    늘 느끼지만 이렇게 대소비교가 확실한 문제는 그리디하게 풀어도 되었던거 같았다.

    1.큰 수 일수록
        - 0의 빈도를 줄이기 위해 노력하며
        - M이 최소한으로 연속되도록 하여 K가 나오는 즉시 끊어버린다.
        - 단 M각각을 1로 쪼갤수도 있으므로, 만약 마지막 까지 K가 안나오고 M만 나열된다면
        M을 전부 1로 쪼개서 추가한다

        (그니까, MMMM이라면
        1000보다 1111이 더 낫다)

        가령 KMMKMKMMK 라면
        K -> 5로 즉시 치환
        MMK -> 500으로 치환
        MK -> 50으로 치환
        MMK -> 500으로 치환

        따라서 550050500

    2. 작은 수 일수록
        - 0의 빈도를 최대한 늘리기 위해 노력하며
        - M과 K를 분리하기 위해 노력한다.

        가령 KMMKMKMMK 라면
        K -> 5로 즉시 치환 (그냥 어쩔수 없음 이건)
        MM -> 10으로 치환
        K -> 5로 치환
        M -> 1로 치환
        K -> 5로 치환
        MM -> 10으로 치환
        K -> 5로 치환

        따라서 510515105


    그리고 일단 기본 룰은 이렇다.

    1. M이 등장한다면, 그 뒤에는 M이나 K 둘 다 아무거나 와도 된다.심지어 끊어도 됨 (선택임)
    2. K가 등장한다면, 반드시 거기에서 끊어야 한다.

    이 기본 룰을 잘 받아들여, 위의 규칙 대로 큰 수와 작은 수를 그리디하게 찾으면 될거 같다



    암튼 예제를 보자

    MKM

    큰 경우
    MK -> 50
    M -> 1

    작은 경우
    M -> 1
    K -> 5
    M -> 1
*/

void max_num(string s)
{

    stringstream ss;
    stringstream temp_ss;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'K')
        {
            ss << '5' << temp_ss.str();
            temp_ss.str("");
            temp_ss.clear();
        }
        else
        {
            if (i < s.size() - 1)
                temp_ss << '0';
            else if (i == s.size() - 1)
            {
                for (int j = 0; j < temp_ss.str().size(); ++j)
                {
                    ss << '1';
                }
                ss << '1';
            }
        }
    }

    cout << ss.str() << "\n";
}

void min_num(string s)
{

    stringstream ss;
    stringstream temp_ss;

    for (int i = 0; i < s.size(); ++i)
    {

        if (s[i] == 'K')
        {
            ss << '5';
        }
        else
        {
            // 내 앞자리가 K인걸 알거나, 그냥 마지막 수까지 M으로 채워졌다면
            // 바로 temp_ss를 소모해서 1을 채워넣어주면 된다.
            if ((i < s.size() - 1 && s[i + 1] == 'K' || i == s.size() - 1))
            {
                ss << '1' << temp_ss.str();
                temp_ss.str("");
                temp_ss.clear();
            }
            else
            {
                temp_ss << '0';
            }
        }
    }

    cout << ss.str() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    max_num(s);
    min_num(s);
}
