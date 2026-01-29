#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
    I 1
    V 5
    X 10
    L 50
    C 100
    D 500
    M 1000
    IV 4
    IX 9
    XL 40
    XC 90
    CD 400
    CM 900


    규칙 1. I,X,C,M은 연속 세번까지, V,L,D, IV,IX,XL,XC,CD,CM는 한번씩만 사용 가능함
    규칙 2. IV와 IX, XL과 XC, CD와 CM은 같이 쓸 수 없음
    규칙 3. 큰 숫자를 반드시 오른쪽에 써야 하며, 각각을 더한 값을 구하면 됨.
    규칙 4. 최대한 최소 개수의 로마 숫자들로 아라비아 숫자를 표현해야함


    내 생각

    - IV, IX... 이것들은 규칙 1에 위배되는 것을 방지하기 위한 안전장치다.
    - 토큰을 어떻게 읽을 것이냐가 중요하다. IV, IX...와 같은 상황을 위해, 뒷자리도 함께 읽는 로직이 필요함
    - 사실 어떤 문자를 몇번 썼냐는 걸 점검하는 건 거의 중요하지 않다.규칙 4를 맞추려는 과정에서 알아서 그 규칙에
    맞게 짜여지게 설계 되어있는 문제다.
    - 딱 하나, 80, 800같은 경우는 40, 400이 두번 들어갈 여지가 있으므로 점검은 해줘야 한다.
    - 의외로 하드 코딩 하는 게 가장 쉬운 문제라고 생각한다...

*/

unordered_map<string, int> roma_map = {
    {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};

unordered_map<int, string> arabia_map = {
    {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"}, {100, "C"}, {500, "D"}, {1000, "M"}, {4, "IV"}, {9, "IX"}, {40, "XL"}, {90, "XC"}, {400, "CD"}, {900, "CM"}};

int divide_order[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

int to_arabia(string r_n)
{

    if (r_n.size() == 1)
    {
        return roma_map[r_n];
    }

    stringstream ss_token;

    int idx = 0;
    int sum = 0;

    while (idx < r_n.size())
    {
        string s1 = "";
        string s2 = "";

        s1 = r_n[idx];
        if (idx + 1 < r_n.size())
            s2 = r_n[idx + 1];

        if (s2 != "" && roma_map[s1] < roma_map[s2])
        {
            ss_token << s1 << s2;
            idx += 2;
        }
        else if (s2 != "" && roma_map[s1] >= roma_map[s2])
        {
            ss_token << s1;
            idx += 1;
        }
        else
        {
            ss_token << s1;
            idx += 1;
        }

        sum += roma_map[ss_token.str()];
        ss_token.str("");
        ss_token.clear();
    }
    // cout << sum << endl;
    return sum;
}

string to_roma(int a_n)
{

    stringstream ss;

    for (int i = 0; i < 13; ++i)
    {
        int divider = divide_order[i];
        string roma = arabia_map[divider];

        int result = a_n / divider;
        int rest = a_n % divider;

        if (i % 2 == 0)
        {
            for (int i = 0; i < result; ++i)
            {
                ss << roma;
            }
        }
        else
        {
            if (result == 1)
                ss << roma;
            else
                continue;
        }

        a_n = rest;
    }
    // cout << ss.str() << endl;
    return ss.str();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s1, s2;

    cin >> s1 >> s2;

    int a1 = to_arabia(s1);
    int a2 = to_arabia(s2);

    int ans_arabia = a1 + a2;
    string ans_roma = to_roma(ans_arabia);

    cout << ans_arabia << "\n"
         << ans_roma;
}
