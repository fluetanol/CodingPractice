
#if 01
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using Point = pair<int, int>;

vector<vector<char>> init_bomb;
vector<vector<char>> all_bomb;
vector<vector<char>> reverse_bomb;
vector<vector<char>> second_init_bomb;

Point dp[5] = {{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int R, C, N;
    cin >> R >> C >> N;

    vector<vector<char>> board(R, vector<char>(C));
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> board[i][j];
        }
    }

    init_bomb = board;
    all_bomb.assign(R, vector<char>(C, 'O'));
    reverse_bomb.assign(R + 2, vector<char>(C + 2, 'O'));
    second_init_bomb.assign(R + 2, vector<char>(C + 2, 'O'));

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if ('O' == board[i][j])
            {
                for (int k = 0; k < 5; ++k)
                {
                    reverse_bomb[i + 1 + dp[k].first][j + 1 + dp[k].second] = '.';
                }
            }
        }
    }
    reverse_bomb.erase(reverse_bomb.begin());
    reverse_bomb.pop_back();
    for (int i = 0; i < reverse_bomb.size(); i++)
    {
        reverse_bomb[i].erase(reverse_bomb[i].begin());
        reverse_bomb[i].pop_back();
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            if ('O' == reverse_bomb[i][j])
            {
                for (int k = 0; k < 5; ++k)
                {
                    second_init_bomb[i + 1 + dp[k].first][j + 1 + dp[k].second] = '.';
                }
            }
        }
    }
    second_init_bomb.erase(second_init_bomb.begin());
    second_init_bomb.pop_back();
    for (int i = 0; i < second_init_bomb.size(); i++)
    {
        second_init_bomb[i].erase(second_init_bomb[i].begin());
        second_init_bomb[i].pop_back();
    }

    vector<vector<char>> target;

    if (N % 2 == 0)
    {
        target = all_bomb;
    }
    else if (N == 1)
    {
        target = init_bomb;
    }
    else if (N % 4 == 1)
    {
        target = second_init_bomb;
    }
    else if (N % 4 == 3)
    {
        target = reverse_bomb;
    }

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cout << target[i][j];
        }
        cout << "\n";
    }

    return 0;
}

#endif

// 참조 링크 : https://www.acmicpc.net/source/101219299

/*
    

    이 사람 풀이는 무려 0ms대가 나왔다.


*/#