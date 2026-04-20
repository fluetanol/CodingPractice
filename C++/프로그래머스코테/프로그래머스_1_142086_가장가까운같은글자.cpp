#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer(s.size());

    vector<int> alpha(26, -1);

    for (int i = 0; i < s.size(); ++i)
    {
        char c = s[i] - 'a';

        if (alpha[c] == -1)
        {
            answer[i] = -1;
        }
        else
        {
            answer[i] = i - alpha[c];
        }

        alpha[c] = i;
    }

    return answer;
}