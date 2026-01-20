#include <iostream>

char board[200][200];
int count[200][200];

int r, c, n;

void Bomb(int i, int j)
{
    board[i][j] = '.';
    if (i + 1 < r)
    {
        board[i + 1][j] = '.';
    }
    if (i - 1 >= 0)
    {
        board[i - 1][j] = '.';
    }
    if (j + 1 < c)
    {
        board[i][j + 1] = '.';
    }
    if (j - 1 >= 0)
    {
        board[i][j - 1] = '.';
    }
}

void Count()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (count[i][j] > 0)
            {
                count[i][j]--;
                if (count[i][j] == 0)
                {
                    Bomb(i, j);
                }
            }
        }
    }
}

void Fill()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = 'O';
                count[i][j] = 3;
            }
            else if (board[i][j] == 'O')
            {
                count[i][j]--;
            }
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> r >> c >> n;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cin >> board[i][j];
            if (board[i][j] == 'O')
            {
                count[i][j] = 2;
            }
        }
    }

    int timer = 1;
    while (timer < n)
    {
        if (timer < n)
        {
            Fill();
            timer++;
        }
        if (timer < n)
        {
            Count();
            timer++;
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}

// 참조 링크 https://www.acmicpc.net/source/101984652

/*
    이 방법은 큐를 이용하지 않고, 3초를 점점 빼가며 0초가 되었을 때 폭탄을 터뜨리는 방식이다.

    즉, 매 초마다 폭탄을 설치할지, 폭탄을 터뜨릴지 고민하는 대신

    매 초마다 폭탄이 터질 때까지 남은 시간을 1초씩 빼가며, 0초가 되었을 때 폭탄을 터뜨리는 것이다.

    물론 이 과정에서 매번 n*n 의 배열을 훑어서 초수를 계속 빼고, 0초인 부분은 터뜨리고, 또 그 다음 초에서 폭탄을 설치하는 등의

    작업이 필요하긴 하지만,

    기존에 내가 사용한 큐를 활용한 방식으로 큐에 push, pop을 하는 추가 오버헤드가 들어가는 것과,

    stringstream 에 str을 추가 하는 오버헤드가 들어가는 것 보다 (물리적으로) 더 빠르기 때문에

    실제 이 분의 풀이는 20ms로 내가 나온 64ms보다 더 빠른 시간이 나왔다.


    좀 더 생각 흐름을 정리해보자면

    나의 관점은 "전체 시간을 흐르게 하고, 짝수 초는 폭탄 설치, 홀수 초는 폭탄 폭발" 이라는 규칙성을 이용하여
    "지금 시간 대에 해야 할 폭탄 설치와 폭탄 폭발" 을 번갈아가며 처리하는 방식이었다면,

    이 사람의 관점은 모든 칸에 대해 "각 칸에 설치된 폭탄이 터질 때까지 남은 시간" 을 기록해두고,
    매 초마다 그 시간을 1초씩 빼가며, 0초가 되었을 때 폭탄을 터뜨리는 방식이었다.
*/