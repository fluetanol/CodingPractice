#include <iostream>
#include <sstream>
#include <unordered_map>

using namespace std;

/*
    펠린드롬 수는 앞으로 읽든 뒤로 읽든 같은 숫자임



    홀수개

    정리
    left = right 면 다음으로 넘어간다
    left > right 면 그 위치부터 대칭을 맞춰준다
    left < right 면, 가운데서부터 전파해 나가 1을 올린다.
    처음부터 대칭이였다면, 그것 또한 가운데서부터 전파해나가 1을 올린다.
    예외로 9로만 이루어져 있다면 앞뒤로 1, 그 중간에는 0으로 채워진 문자열을 만들면 됨


    짝수개

    정리
    left = right 면 다음으로 넘어간다
    left > right 면 그 위치에서부터 대칭을 맞춰준다.
    left < right 면 가운데서부터 1씩 올려준다.
    처음부터 대칭이였다면 그것 또한 가운데서부터 1을 올린다.
    예외로 9만 이루어져있다면...



    아무튼 정리하면 이것도 그리디한 방식의 풀이라고 볼 수 있다.

    1. 최대한 앞자리수를 바꾸려하면 안된다.
    2. 최대한 뒷자리수부터 바꾸기 위해 노력해야한다.
*/

void setting(int &left, int &right, int mid, int size)
{
    if (size % 2 == 0)
    {
        left = mid - 1;
        right = mid;
    }
    else
    {
        left = mid - 1;
        right = mid + 1;
    }
}

string next_pelindrome(string s)
{

    int mid = s.size() / 2;
    int left = 0;
    int right = 0;

    setting(left, right, mid, s.size());

    int flag = 0;
    for (int i = 0; i < mid; ++i)
    {
        char c_l = s[left - i];
        char c_r = s[right + i];

        if (flag == 0)
        {
            if (c_l == c_r)
            {
                // 대칭 케이스 검증
                if (i == mid - 1)
                {
                    flag = 2;
                    break;
                }
                continue;
            }
            // 대칭으로 만들어도 되는 케이스 검증
            else if (c_l > c_r)
            {
                s[right + i] = c_l;
                flag = 1;
            }
            // 가운데를 올리는 작업을 함
            else if (c_l < c_r)
            {
                flag = 3;
                break;
            }
        }

        else if (flag == 1)
        {
            s[right + i] = c_l;
        }
    }

    // 9로만 덮혀있는 특수케이스인지 검증
    if (flag == 2)
    {
        // cout << "대칭수" << endl;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '9')
                count++;
        }
        if (count == s.size())
        {
            stringstream ss;
            ss << "1";
            for (int i = 0; i < s.size() - 1; ++i)
            {
                ss << "0";
            }
            ss << "1";
            s = ss.str();
        }
        else
        {
            flag = 3;
        }
    }

    // left< right인 케이스
    if (flag == 3)
    {
        // cout << "중앙 업데이트" << endl;
        setting(left, right, mid, s.size());

        // 자릿수가 홀수인 경우 중앙이 9로 인해 받아올림을 해야 하는 전처리
        if (s.size() % 2 == 1 && s[mid] != '9')
        {
            s[mid] += 1;
            flag = 4;
        }
        else if (s.size() % 2 == 1 && s[mid] == '9')
        {
            s[mid] = '0';
        }

        // 그 외에는 그냥 똑같이 흘러가게함
        for (int i = 0; i < mid; ++i)
        {
            char c_l = s[left - i];
            char c_r = s[right + i];

            if (flag != 4)
            {
                if (c_l != '9')
                {
                    s[left - i] = c_l + 1;
                    s[right + i] = s[left - i];
                    flag = 4;
                }
                else
                {
                    s[left - i] = '0';
                    s[right + i] = s[left - i];
                }
            }
            else
            {
                s[right + i] = c_l;
            }
        }
    }

    return s;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;

    // 한자릿수 특수 케이스 검증
    if (s.size() == 1 && s != "9")
    {
        cout << char(s[0] + 1);
        return 0;
    }
    else if (s == "9")
    {
        cout << "11";
        return 0;
    }

    cout << next_pelindrome(s);
}
