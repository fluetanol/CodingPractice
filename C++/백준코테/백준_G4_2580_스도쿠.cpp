#include <iostream>
#include <vector>

using namespace std;

int map[9][9];

// 스도쿠
/*
    정사각형, 수직으로 1~9까지 있는지만 체크

    0. 빈 칸의 위치 pair를 미리 벡터에 넣어둠
    1. 0,0 부터 읽어나감
    2. 숫자 하나를 정한 뒤 그 숫자가 가로, 세로, 9칸 사이에 존재하는 지 확인함
    3. 넣을 수 있으면 넣은 뒤, 다음 위치로 이동하여 넣을 수 있는 지 또 체크함
    4. 계속 넘어가다가, 더 이상 못 넣는 케이스가 오면 백트래킹
*/

bool row(int r, int val)
{
    for (int i = 0; i < 9; ++i)
    {
        if (map[r][i] == val)
        {
            return false;
        }
    }
    return true;
}

bool col(int c, int val)
{
    for (int i = 0; i < 9; ++i)
    {
        if (map[i][c] == val)
        {
            return false;
        }
    }
    return true;
}

bool matrix(int r, int c, int val)
{
    int start_r = (r / 3) * 3;
    int start_c = (c / 3) * 3;

    for (int i = start_r; i < start_r + 3; ++i)
    {
        for (int j = start_c; j < start_c + 3; ++j)
        {
            if (map[i][j] == val)
            {
                return false;
            }
        }
    }
    return true;
}

bool tracking(vector<pair<int, int>> &empty, int idx)
{
    if (idx == empty.size())
    {
        return true;
    }

    pair<int, int> pos = empty[idx];

    int r = pos.first;
    int c = pos.second;
    bool finish = false;

    for (int i = 1; i <= 9; ++i)
    {
        if (row(r, i) && col(c, i) && matrix(r, c, i))
        {
            map[r][c] = i;
            finish = tracking(empty, idx + 1);
            if (!finish)
                map[r][c] = 0;
        }

        if (finish)
            break;
    }

    return finish;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, int>> empty;

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 0)
            {
                empty.push_back({i, j});
            }
        }
    }

    tracking(empty, 0);

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}
