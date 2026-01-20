#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

// 폭탄 문자 : O  (알파벳인가?)
/*
   - 규칙 정리
   0초 : 폭탄 설치
   1초 : 유기
   2초 : 나머지 칸에 폭탄 설치
   3초 : 0초때 폭탄 폭발 (0+3)
   4초 : 나머지 칸에 폭탄 설치
   5초 : 2초때 폭탄 폭발 (2+3)
   ...

   - 구현
   1. 0초때 설치될 폭탄을 큐에 넣어둔다. 큐의 정보는 (i, j, t)로 들어가게 될 예정
   2. 유기는 어차피 문제를 위해 시간을 끌기 위한 상황이니 무시
   3. 첫 시작을 2초라 가정하고,
   나머지 칸에 폭탄을 설치 해두며, 이 때 또 큐의 정보는 i, j, t로 저장해둔다.
   이러면 이제 큐에 들어가는 t는 0,2,4,6,8... 단위로 계속 저장될 예정 (짝수 초)
   4. 첫 폭발 시간은 3초이며, 이때부터 큐에 3-3 = 0초로 기록된 모든 폭탄을 터뜨린다.
   5. 이후 짝수 시간마다 폭탄 설치, 홀수 시간마다 폭탄 폭발을 반복한다...

   근데 뭔가 이상하지 않은가?
   만약 4번에 의해 폭탄이 터지면 이미 설치된 폭탄 중에서 사라질 폭탄도 있을 건데, 그것들은
   3번을 진행하는 과정에 그 폭탄 정보가 있을 것이다...

   그래서 이렇게 추가해둔다.

   3. 나머지 칸에 폭탄을 설치 해두며, i, j, t로 저장해두고,
   set 자료구조에도 해당 위치를 추가로 저장해둔다.

   4. 폭탄이 터질 때, set자료구조에 해당 위치를 지워둠.

   5. 짝수 시간마다 폭탄 설치 후 큐와 set에 저장, 홀수 시간마다 해당 구조체가 set에 있는지 체크 후
   유효 폭탄인지 확인하고, 그게 맞다면 폭발


   근데 이러면 또 set에 대한 오버헤드가 발생할거 같다. (참고로 unordered set이긴 함)

   그럼 더 좋은 방법으로, 한 칸에는 반드시 단 하나의 폭탄만 설치 가능하다는 점을 이용해볼까


   3. 나머지 칸에 폭탄을 설치 하며 i,j, t로 저장해둔다.
   그 다음, 몇초에 설치해둔 폭탄인지를 기록할 수 있는 별도의 i*j 의 bomb 배열을 두고,
   그 bomb 배열에 "가장 최근에 설치된 폭탄"의 초를 기록해둔다.

   4. 폭탄이 터질 때, 터진 폭탄들은 모두 bomb 배열에 -1을 기록해둔다.


   5. 짝수 시간마다 다시 설치할 땐 배열을 훑어 -1로 저장된 위치에 폭탄을 설치해두고 다시 설치한
   시간을 기록한다.
   반대로 홀수 시간마다 다시 폭발 할 땐, 큐에 있는 정보의 설치 초와 현재 bomb 배열의 시간 초가
   일치한지 확인하여 유효성을 검사한다.
   유효하다면 그 폭탄을 모두 터뜨린다.




*/

struct bomb_info
{
    int r;
    int c;
    int t;
};

void bomb_install(vector<vector<int>> &v_bomb_time, queue<bomb_info> &q, int r, int c, int t)
{
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            // 비어있는 자리에 폭탄 채워넣고, 현재 시간 초 기록
            if (v_bomb_time[i][j] == -1)
            {
                v_bomb_time[i][j] = t;
                q.push({i, j, t});
            }
        }
    }
}

int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};

bool isRange(int i, int j, int r, int c)
{
    return i >= 0 && j >= 0 && i < r && j < c;
}

void bomb_bomb(vector<vector<int>> &v_bomb_time, queue<bomb_info> &q, int r, int c, int t)
{

    // 어차피 t는 낮은 것 부터 높은 순서로 나열 저장 되어 있을 것이라 이렇게 해도 됨
    while (!q.empty() && q.front().t == t)
    {
        bomb_info b_info = q.front();
        int b_r = b_info.r;
        int b_c = b_info.c;
        int b_t = b_info.t;
        q.pop();

        if (b_t != v_bomb_time[b_r][b_c])
        {
            continue;
        }
        else
        {
            for (int i = 0; i < 5; ++i)
            {
                int delta_r = b_r + dx[i];
                int delta_c = b_c + dy[i];

                if (isRange(delta_r, delta_c, r, c))
                {
                    // 자기랑 같은 시간대에 동시에 터질 폭탄이면 무시해야함
                    // 그 폭탄도 터지는 걸 보장해야하기 때문
                    // 만약 값 변조로 인해 b_t 체크 구문에서 삑살 나면 안터짐
                    if ((delta_r != b_r || delta_c != b_c) && v_bomb_time[delta_r][delta_c] == b_t)
                    {
                        continue;
                    }

                    v_bomb_time[delta_r][delta_c] = -1;
                }
            }
        }
    }
}

void bomber_man(vector<vector<int>> v_bomb_time, queue<bomb_info> &q, int r, int c, int n)
{

    for (int t = 2; t <= n; ++t)
    {
        // 폭탄 설치
        if (t % 2 == 0)
        {
            bomb_install(v_bomb_time, q, r, c, t);
        }
        // 폭탄 폭발
        else
        {
            bomb_bomb(v_bomb_time, q, r, c, t - 3);
        }
    }

    vector<string> v_map(r);
    stringstream ss;
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            ss << (v_bomb_time[i][j] == -1 ? "." : "O");
        }
        ss << "\n";
    }

    cout << ss.str() << endl;
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int r, c, n;
    cin >> r >> c >> n;

    vector<string> v(r);
    queue<bomb_info> q;

    for (int i = 0; i < r; ++i)
    {
        cin >> v[i];
        for (int j = 0; j < c; ++j)
        {
            if (v[i][j] == 'O')
            {
                q.push({i, j, 0});
            }
        }
    }

    vector<vector<int>> v_bomb_time(r, vector<int>(c, -1));
    for (int i = 0; i < r; ++i)
    {
        for (int j = 0; j < c; ++j)
        {
            if (v[i][j] == 'O')
            {
                v_bomb_time[i][j] = 0;
            }
        }
    }

    bomber_man(v_bomb_time, q, r, c, n);
}
