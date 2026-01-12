#include <iostream>
#include <queue>
using namespace std;

void perm_find_destarray(vector<int> &v_in, vector<bool> &visited, int depth, int &count, int dest)
{
    if (depth == v_in.size())
    {
        count++;
        return;
    }

    for (int i = 0; i < v_in.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v_in[depth] = i + 1;
            perm_find_destarray(v_in, visited, depth + 1, count, dest);

            if (count == dest)
                return;

            visited[i] = false;
        }
    }
}

void perm_find_destcount(vector<int> &v_in, vector<bool> &visited, int depth, int &count, bool &isDest, vector<int> &v_dest)
{
    if (depth == v_in.size())
    {
        isDest = true;
        for (int i = 0; i < depth; ++i)
        {
            if (v_dest[i] != v_in[i])
            {
                isDest = false;
                break;
            }
        }
        count++;
        return;
    }

    for (int i = 0; i < v_in.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            v_in[depth] = i + 1;
            perm_find_destcount(v_in, visited, depth + 1, count, isDest, v_dest);
            if (isDest)
                return;
            visited[i] = false;
        }
    }
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int k;
    cin >> k;

    vector<int> v_in(n);
    vector<bool> visited(n);
    int count = 0;

    if (k == 1)
    {
        int dest;
        cin >> dest;
        perm_find_destarray(v_in, visited, 0, count, dest);
        for (int i = 0; i < n; ++i)
        {
            cout << v_in[i] << " ";
        }
        cout << "\n";
    }
    else
    {
        bool isDest = false;
        vector<int> v_dest(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> v_dest[i];
        }
        perm_find_destcount(v_in, visited, 0, count, isDest, v_dest);
        cout << count;
    }
}

/*
    이 방식은 fail된 방식인데,
    직접 순열을 만들어가면서 찾는 방식으로, N = 20이 되면 20!이나 되는 가짓수를 점검해야 해서
    엄청난 오버헤드가 발생한다.
    즉 시간초과가 발생한다.
*/