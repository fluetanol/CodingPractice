#include <string>

using namespace std;

int solution(int n)
{
    int answer = 0;

    int i = 0;
    int x = 0;
    while (true)
    {
        ++x;

        string s = to_string(x);
        bool flag = false;

        if (x % 3 == 0)
            continue;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '3')
            {
                flag = true;
                break;
            }
        }

        if (flag)
            continue;

        ++i;

        if (n == i)
        {
            break;
        }
    }

    answer = x;

    return answer;
}