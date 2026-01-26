
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

    폭발의 주기성을 이용한 굉장히 똑똑한 풀이다.
    
    요약하면 0, 1초는 초기 상태

    짝수 초는 무조건 폭탄이 가득 찬 상태

    홀수 초는 3, 7, 11... 을 주기로 동일한 형태

    또 5, 9, 13... 을 주기로 동일한 형태를 이루는데

    이 점을 이용하여 주어진 N의 상태에 따라 저장해둔 네 가지 상태 중 하나를 골라 출력하는 방식이다...!

    이 주기성에 대한 내용은 말하면 길어지니 노션에 기록해두겠음.


*/#