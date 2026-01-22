#include <iostream>
#include <vector>

using namespace std;

/*
    모든 상점 간에 거리 합이 가장 작아야 한다
    = 모든 상점간 동근이와의 거리가 최단 거리면 전체 합도 가장 작아진다

    갈수 있는 방법은 시계방향과 반시계 방향이 끝이다.

    이렇게 생각해보자

    1. 시계방향으로 움직인다. 만약 1, 2면 좌우로, 3,4 면 상하로 움직이면 됨
    2. 원점으로 되돌아올 때 까지 반복하며, 그 과정에서 만난 모든 상점들간 거리를 기록한다.
    3. 반대방향으로도 돌아본다. 마찬가지로 그 과정에서 만난 모든 상점들 간 거리를,
    이미 기록된 거리와 비교하여 더 작다면 갱신한다.
    4. 합을 구한다.


    북쪽은 r = 0, 남쪽은 r= size-1
    동쪽은 c = size-1, 서쪽은 c= 0;

*/
// 동 , 북, 서, 남
int dr[4] = {0, -1, 0, 1};
int dc[4] = {1, 0, -1, 0};

bool isRange(int i, int j, int r, int c)
{
    return i >= 0 && j >= 0 && i <= r && j <= c;
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int r, c, n;
    cin >> c >> r >> n;

    int map[101][101];
    int store_count[101][101];

    int my_r = 0, my_c = 0, my_dir = 0;

    for (int i = 0; i <= r; ++i)
    {
        for (int j = 0; j <= c; ++j)
        {
            map[i][j] = -1;
            store_count[i][j] = 0;
        }
    }

    for (int i = 0; i <= n; ++i)
    {
        int dir, offset;
        cin >> dir >> offset;

        // 북 ( r = 0 )
        if (dir == 1)
        {
            if (i < n)
            {
                map[0][offset] = 0;
                store_count[0][offset]++;
            }
            else
            {
                my_r = 0;
                my_c = offset;
            }
        }
        // 남 ( r = size - 1)
        else if (dir == 2)
        {
            if (i < n)
            {
                map[r][offset] = 0;
                store_count[r][offset]++;
            }
            else
            {
                my_r = r;
                my_c = offset;
            }
        }
        // 서 ( c = 0 )
        else if (dir == 3)
        {
            if (i < n)
            {
                map[offset][0] = 0;
                store_count[offset][0]++;
            }
            else
            {
                my_r = offset;
                my_c = 0;
            }
        }
        // 동 ( c = size-1 )
        else if (dir == 4)
        {
            if (i < n)
            {
                map[offset][c] = 0;
                store_count[offset][c]++;
            }
            else
            {
                my_r = offset;
                my_c = c;
            }
        }

        if (i == n)
        {
            my_dir = dir;
        }
    }

    // cout << my_r << " " << my_c << endl;
    // cout <<"-----------------"<< endl;
    // 우측 방향으로 갈지, 아래측 방향으로 갈지 정하는 로직
    int d_mode = (my_dir == 1 || my_dir == 2) ? 0 : 1;
    int sum = 0;

    while (d_mode < 4)
    {
        // 원점으로부터 거리 count
        int count = 0;
        int temp_my_r = my_r;
        int temp_my_c = my_c;
        int mode = d_mode;
        // cout << "mode : " << mode << endl;
        while (true)
        {
            temp_my_r = temp_my_r + dr[mode];
            temp_my_c = temp_my_c + dc[mode];

            // 원점 복귀는 break
            if (temp_my_r == my_r && temp_my_c == my_c)
            {
                // cout << "finish" << endl;
                break;
            }
            bool is_range = isRange(temp_my_r, temp_my_c, r, c);

            // 한번도 안둘러본 곳
            if (is_range && map[temp_my_r][temp_my_c] == 0)
            {
                count++;
                map[temp_my_r][temp_my_c] = count;
                sum += count * store_count[temp_my_r][temp_my_c];
                // cout << "meet the store! : " << sum << "\n";
            }
            else if (is_range && map[temp_my_r][temp_my_c] > 0)
            {
                count++;
                // 갱신해야 하는 경우 (더 작아서)
                if (map[temp_my_r][temp_my_c] > count)
                {
                    // 이전 값 버리고 새로운 값을 더함
                    sum -= (map[temp_my_r][temp_my_c] * store_count[temp_my_r][temp_my_c]);
                    map[temp_my_r][temp_my_c] = count;
                    sum += (count * store_count[temp_my_r][temp_my_c]);
                }
                // cout << "meet the store again -> : " << sum << "\n";
            }
            // 회전 해야 함
            else if (!is_range)
            {

                temp_my_r = temp_my_r - dr[mode];
                temp_my_c = temp_my_c - dc[mode];

                if ((d_mode == 2 && my_dir == 1) ||
                    (d_mode == 0 && my_dir == 2) ||
                    (d_mode == 3 && my_dir == 3) ||
                    (d_mode == 1 && my_dir == 4))
                    mode = (mode + 1) % 4;

                else
                    mode = (4 + mode - 1) % 4;

                // cout << "turn  new mode : " << mode << "\n";
            }
            else
            {
                count++;
            }
            // cout << temp_my_r << " " << temp_my_c << " " << count << "\n";
        }

        // 반 시계 방향
        d_mode = d_mode + 2;
        // cout << "-------" << endl;
    }

    cout << sum;
}

// 북(1)에서 시작하는 경우 시계 = 동 -> 남 -> 서 -> 북
//  따라서 시작 인덱스는 0--, 2++

// 남(2)에서 시작하는 경우 시계 = 서 -> 북 -> 동 -> 남
// 반시계면 그냥 이것의 반대로
//  동 -> 북 -> 서 -> 남
// 따라서 시작 인덱스는 2--, 0++임

// 서(3)에서 시작하는 경우 시계 = 북 -> 동 -> 남 -> 서
//  시작 인덱스는 1-- 3++

// 동(4)에서 시작하는 경우 시계 = 남 -> 서 -> 북 -> 동
//  시작 인덱스는 3-- 1++


/*
    이 풀이는 2차원 배열을 이용한 시뮬레이션 풀이이다.
    진짜 둘레를 도는 것처럼 구현하는 것인데
    굉장히 복잡해서 실수할 확률이 높았다...
    
    참고로 이 문제는 좆같은 테스트 케이스가 하나 있는데,

    상점의 위치가 동일한 곳에 여러개가 있을 수 있다는 점이다.

    문제 설명 자체에 "상점의 위치는 동일한 위치에 있을 수 없다"
    라는 말이 없기 때문에 그게 가능했던건데...

    진짜 너무하네
    기왕이면 좀 직관적으로 적는게 인지상정 아닌가?

*/