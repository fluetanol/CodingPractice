#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class node
{
public:
    node **node_arr;
    bool is_word = false;

    node()
    {
        node_arr = new node *[10]{NULL};
    }
};

void insert(node *n, string s, int idx)
{
    if (idx == s.size())
    {
        n->is_word = true;
        return;
    }

    int c = s[idx] - '0';

    if (n->node_arr[c] == NULL)
    {
        n->node_arr[c] = new node();
    }

    insert(n->node_arr[c], s, idx + 1);
    return;
}

bool fetch(node *n, string s, int idx)
{
    if (idx == s.size())
    {
        return true;
    }
    if (n->is_word)
    {
        return false;
    }

    int c = s[idx] - '0';

    return fetch(n->node_arr[c], s, idx + 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    int n;

    cin >> t;

    for (int tc = 0; tc < t; ++tc)
    {

        cin >> n;

        node *root = new node();

        vector<string> v(n);
        for (int i = 0; i < n; ++i)
        {
            string s;
            cin >> s;
            insert(root, s, 0);
            v[i] = s;
        }

        bool flag = true;
        for (int i = 0; i < n; ++i)
        {
            string s = v[i];

            if (!fetch(root, s, 0))
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}
