// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2Base64Decorder
// 24/04/23
// 1시간 반;;;

#include <iostream>
#include <cmath>
using namespace std;

string Binary(int dec)
{
    int a = 0b100000;
    string s = "";
    for (int i = 0; i < 6; i++)
    {
        if (dec & a)
            s += '1';
        else
            s += '0';
        a = a >> 1;
    }
    return s;
}

void Decicharacter(string binary)
{
    int idx = 0;
    string sbinary = binary.substr(idx, 8);
    while (sbinary != "")
    {
        int deci = 0;
        for (int i = 7; i >= 0; i--)
        {
            deci += (sbinary[i] - '0') * pow(2, 7 - i);
        }
        cout << (char)deci;
        idx += 8;
        sbinary = binary.substr(idx, 8);
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        cin >> s;
        int idx = 0;
        string ss = s.substr(idx, 4);
        cout << "#" << test_case << " ";
        while (ss != "")
        {
            string binary = "";
            for (int i = 0; i < 4; i++)
            {
                int code = -1;
                if ('A' <= ss[i] && ss[i] <= 'Z')
                    code = ss[i] - 'A';
                else if ('a' <= ss[i] && ss[i] <= 'z')
                    code = ss[i] - 'a' + 26;
                else if ('0' <= ss[i] || ss[i] <= '9')
                    code = ss[i] - '0' + 52;
                else if (ss[i] == '+')
                    code = 62;
                else if (ss[i] == '/')
                    code = 63;
                binary += Binary(code);
            }
            Decicharacter(binary);
            idx += 4;
            ss = s.substr(idx, 4);
        }
        cout << endl;
    }

    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//악랄한 문제.
//일단 base64인코딩 방식을 이미 아는 사람이라면 쉽게 풀 문제는 맞는데
//난관이 몇개 있다

//1. 저 인코딩 표
//문자 인코딩 숫자 변환의 규칙이 단순한 문자-'A'가 아니다.
//문자 특성에 따라 구간별로 달리 조건을 세워서 변환 시켜줘야 한다
//이 부분 못알아채서 20분 허비함

//2. DECI -> BINARY -> DECI
//이거 구현이 사람 짜증나게 만든다
//DECI -> BINARY는 6비트 단위로
//BINARY -> DECI는 8비트 단위로 이루어져야 한다...

//3. 캐스팅과 문자열
//문자열 -> 정수 (캐릭터) -> 문자열 전환이 계속 이루어지며
//문자열의 substr을 가져오는 작업도 귀찮도록 많다...

// 최적화 요소
// 1. deci->binary는 비트 연산으로 했다. 비트 연산이 압도적으로 빠름
// 2. cout호출 횟수를 줄이는 방향으로 string에 저장하고 한번에 출력하는 방법좀 써야 할듯
// 3. string의 ++연산은 상당한 heap allocation 오버헤드가 들어간다... 
//이에 대한 최적화 방식 참고자료는 https://www.cv-learn.com/20201211-string-concat/ 참고
