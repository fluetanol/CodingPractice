#include <iostream>

using namespace std;

bool isRange(int i, int j)
{
    return i >= 0 && j >= 0 && i < 19 && j < 19;
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int board[19][19] = {};
    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < 19; ++i)
    {
        for (int j = 0; j < 19; ++j)
        {

            // 시작점 색깔
            int color = board[i][j];
            if (color == 0)
                continue;

            bool cond_row = true;
            bool cond_col = true;
            bool cond_dig_right = true;
            bool cond_dig_left = true;

            for (int k = 0; k <= 5; ++k)
            {
                // 하측
                bool is_range_row = isRange(i + k, j);
                // 우측
                bool is_range_col = isRange(i, j + k);
                // 우하측
                bool is_range_dig_right = isRange(i + k, j + k);
                // 좌하측
                bool is_range_dig_left = isRange(i + k, j - k);

                if (k == 0)
                {
                    is_range_row = isRange(i - 1, j);
                    is_range_col = isRange(i, j - 1);
                    is_range_dig_right = isRange(i - 1, j - 1);
                    is_range_dig_left = isRange(i - 1, j + 1);

                    if (is_range_row && board[i - 1][j] == color)
                    {
                        cond_row = false;
                    }
                    if (is_range_col && board[i][j - 1] == color)
                    {
                        cond_col = false;
                    }
                    if (is_range_dig_right && board[i - 1][j - 1] == color)
                    {
                        cond_dig_right = false;
                    }
                    if (is_range_dig_left && board[i - 1][j + 1] == color)
                    {
                        cond_dig_left = false;
                    }
                }
                else if (k < 5 && k >= 1)
                {
                    if ((is_range_row && board[i + k][j] != color) || !is_range_row)
                    {
                        cond_row = false;
                    }

                    if ((is_range_col && board[i][j + k] != color) || !is_range_col)
                    {
                        cond_col = false;
                    }

                    if ((is_range_dig_right && board[i + k][j + k] != color) || !is_range_dig_right)
                    {
                        cond_dig_right = false;
                    }

                    if ((is_range_dig_left && board[i + k][j - k] != color) || !is_range_dig_left)
                    {
                        cond_dig_left = false;
                    }
                }

                else if (k == 5)
                {
                    if (is_range_row && board[i + k][j] == color)
                    {
                        cond_row = false;
                    }
                    if (is_range_col && board[i][j + k] == color)
                    {
                        cond_col = false;
                    }
                    if (is_range_dig_right && board[i + k][j + k] == color)
                    {
                        cond_dig_right = false;
                    }
                    if (is_range_dig_left && board[i + k][j - k] == color)
                    {
                        cond_dig_left = false;
                    }
                }
            }

            if (cond_row || cond_col || cond_dig_left || cond_dig_right)
            {
                // 좌하측 방향이라면 예외적으로 시작점은 좌측으로 잡아야 한다...
                if (cond_dig_left)
                {
                    cout << color << "\n"
                         << i + 5 << " " << j - 3;
                }
                else
                {
                    cout << color << "\n"
                         << i + 1 << " " << j + 1;
                }
                return 0;
            }
        }
    }

    cout << 0;
}

// 문제 잘 안읽으면 멘탈 개털리는 문제
// 좋은 문제라고 생각함
// 풀이는 노션에 정리해놓겠음