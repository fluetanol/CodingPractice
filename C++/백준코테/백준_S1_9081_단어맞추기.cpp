#include <iostream>
#include <vector>
using namespace std;

/*
    아이디어


    ABC

    ACB

    BAC

    BCA

...


    DRIKN
    DRINK
    DRKIN
    DRKNI
    DRNIK
    DRNKI


    DINRK 인 경우
    -> 세번째 자리부터 내림차순으로 꺾임 -> 앞에 있는 것 중 가장 거리상 가까운 더 큰 단어랑 자리 바꿈
    그리고 오름차순 시킴.
    지금은 N보다 큰 가장 가까운 단어가 R밖에 없으니 얘랑 바꿔야 겠슴


    DIRKN (뒤에서)
    -> 두번째 자리부터 내림차순으로 꺾임 -> 서로 자리 바꿈

    DIRNK
    -> 네번째 자리부터 내림차순으로 꺾임 -> I랑 가장 거리 가까운 더 큰 단어는 K이므로 얘랑 이제 자리 바꿈
    그리고 나머지 단어들로 오름차순 시킴


    DKINR
    -> 두번쨰 자리부터 내림차순으로 꺾임 -> 서로 자리 바꿈

    DKIRN
    -> 세번째 자리부터 내림차순으로 꺾임 -> N이 가장 가까우므로 얘랑 자리 바꾸고 또 내림차순 시킴
    DKNIR
    ...


    정리하면 이렇다

    1. 얼마나 오름차순이 되어있는지 확인한다.

    2. 내림차순이 되어있는 자리 K를 발견했다면 (가령 'B'라고 하면)
    B와 거리상 가장 가깝지만 더 뒷단어인 녀석을 하나 골라서 자리를 바꾼다.(단 동일한 문자면 무시함)

    3. 이후 나머지 단어들을 오름차순 시켜서 배치시킨다.

    이게 끝임
    가령 중복 단어가 넘치는

    ABCBA 라고 한다면
    두번째 자리에서 꺾이고, B보다 뒤에 있는 가장 가까운 문자는 C다.
    나머지 B, B, A를 오름차순 시키면

    ACABB
    계속 해보자. 그 다음엔 셋쨰자리 A에서 꺾이므로

    ACBAB

    둘째자리 A에서 꺾이므로

    ACBBA

    이제 첫번째 자리에서 꺾이므로, B가 앞에 나올 것이다.
    나머지 A,C,B,A로 오름차순

    BAABC







*/

// 26자리
string next_string(string s)
{

    vector<int> v(26);
    char c = s[s.size() - 1];

    for (int i = s.size() - 2; i >= 0; --i)
    {
        char c_comp = s[i];
        // 오름차순이라면 넘어갑니다. (카운트 정렬에 캐싱해두고)
        if (c <= c_comp)
        {
            v[c - 'A']++;
            c = c_comp;
            continue;
        }

        // 내림차순이 나왔다면 자리를 바꿔야 합니다.
        else
        {
            v[c - 'A']++;
            v[c_comp - 'A']++;

            // 내림차순이 발견된 글자를 기준으로 자기보다 가장 가까운 거리의 더 큰 글자를 자기 자리에 놔둡니다
            for (int j = c_comp - 'A' + 1; j < v.size(); ++j)
            {
                if (v[j] > 0)
                {
                    s = s.substr(0, i) + char(j + 'A');
                    v[j]--;
                    break;
                }
            }
            // 이후 남은 뒷자리 글자들을 오름차순 시킵니다.
            for (int j = 0; j < v.size(); ++j)
            {
                if (v[j] > 0)
                {
                    for (int k = 0; k < v[j]; ++k)
                        s += char(j + 'A');
                }
            }
            break;
        }
    }

    return s;
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        string s;
        cin >> s;

        cout << next_string(s) << "\n";
    }
}
