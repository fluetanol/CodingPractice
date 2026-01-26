#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

string reverse(string s)
{
    stringstream ss;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        ss << s[i];
    }
    return ss.str();
}

int AB(string s, string t)
{

    while (t.size() > s.size())
    {
        char back = t[t.size() - 1];

        if (back == 'A')
        {
            t = t.substr(0, t.size() - 1);
        }
        else if (back == 'B')
        {
            t = reverse(t.substr(0, t.size() - 1));
        }
        cout << t << endl;
    }

    if (t == s)
        return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, t;
    cin >> s >> t;

    cout << AB(s, t) << "\n";
}
