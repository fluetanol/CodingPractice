#include <iostream>
#include <vector>

using namespace std;

/*
    1. 인접의 의미는 상하좌우를 뜻한다.
    2. 좋아하는 학생이 인접한 칸에 가장 많은 곳으로 자리를 정해야 한다.
    3. 2번을 만족하는 게 여러 개면 비어있는 칸이 가장 많은 칸으로 자리를 정해야 한다.
    4. 3번을 만족하는 게 여러 개면 행, 열 번호가 가장 작은 것을 기준으로 자리를 정한다.
    5. 좌상단은 1, 1 우하단은 n, n이다.


    2번 만족시키려면
    - 전체 배열을 둘러본다.
    이 때 상하좌우 번호를 체크하며, 자신이 좋아하는 학생이 몇 명 있는지를 점검한다.
    좋아하는 학생이 가장 많은 칸을 갱신해서 vector에 집어 넣는다. 유일할 경우, 그냥 그 위치에 배치시킨다.

    3번 만족시키려면
    - 2번에서 만족했던 칸들만 둘러본다.
    이 때 상하좌우 번호를 체크하며, 아무도 없는 칸 (-1)의 개수가 가장 높은 곳을 점검한다.

    4번 만족시키려면
    - 그냥 3번에서 만족했던 칸들 중 가장 작은 걸 가져온다.



    - 좋아하는 학생을 조회하는 방법
    n*n 크기의 배열을 만들고, 바로 랜덤어세스가 가능하도록 좋아하는 친구 여부에 대한 flag를 기록해둔다.

   - 한 칸에 대한 필요 정보
   한 칸을 볼 때 4방향을 봐야 하며, 필요 정보는 이렇다.
   1. 좌표의 위치
   2. 좋아하는 학생의 수
   3. 빈 칸의 수

    - PQ가 필요한가?
    필요 없음 N이 크진 않아서

*/

struct coord_info
{
    pair<int, int> p;
    int likes;
    int emptys;
};

struct student_info
{
    int student;
    int likes;
};

int n;
bool like[400][400] = {false};
student_info map[20][20] = {};
int order[400];
int score[5] = {0, 1, 10, 100, 1000};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int r, int c)
{
    return r >= 0 && c >= 0 && r < n && c < n;
}

coord_info adjacent_search(int r, int c, int student)
{
    coord_info coord_info = {make_pair(r, c), 0, 0};

    for (int i = 0; i < 4; ++i)
    {
        int adj_r = r + dr[i];
        int adj_c = c + dc[i];
        bool is_range = isRange(adj_r, adj_c);
        int adjacent_student = map[adj_r][adj_c].student;

        if (is_range && adjacent_student != -1 && like[student][adjacent_student])
        {
            coord_info.likes++;
        }
        else if (is_range && map[adj_r][adj_c].student == -1)
        {
            coord_info.emptys++;
        }
    }

    return coord_info;
}

void update_likes(int r, int c, int student)
{
    for (int i = 0; i < 4; ++i)
    {
        int adj_r = r + dr[i];
        int adj_c = c + dc[i];
        bool is_range = isRange(adj_r, adj_c);
        int adjacent_student = map[adj_r][adj_c].student;

        if (is_range && adjacent_student != -1 && like[adjacent_student][student])
        {
            map[adj_r][adj_c].likes++;
        }
    }
}

int like_counts(int r, int c, int student)
{
    int count = 0;
    for (int i = 0; i < 4; ++i)
    {
        int adj_r = r + dr[i];
        int adj_c = c + dc[i];
        bool is_range = isRange(adj_r, adj_c);
        int adjacent_student = map[adj_r][adj_c].student;

        if (is_range && adjacent_student != -1 && like[student][adjacent_student])
        {
            count++;
        }
    }
    return count;
}

int seat_down()
{

    vector<coord_info> v_cords;
    v_cords.reserve(n * n);

    for (int i = 0; i < n * n; ++i)
    {

        int order_student = order[i];
        int max_likes = -1;
        // cout << "order " << order_student << endl;

        // 좋아하는 애들이 많은 칸 찾기
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (map[i][j].student != -1)
                    continue;

                coord_info cord = adjacent_search(i, j, order_student);
                // cout << "order_student : " << order_student << " : " << cord.emptys << ", " << cord.likes << endl;

                // 만약 좋아하는 학생 수가 더 많은 칸이 있는 걸로 갱신 되는 경우
                if (cord.likes > max_likes)
                {
                    // cout << "max update : "<< cord.p.first << "," << cord.p.second << endl;
                    max_likes = cord.likes;
                    v_cords.clear();
                    v_cords.push_back(cord);
                }
                // 동일한 칸이 여러개인 경우
                else if (cord.likes == max_likes)
                {
                    // cout << "push : " << cord.p.first << "," << cord.p.second << endl;
                    v_cords.push_back(cord);
                }
            }
        }

        // 참고로 좌상단 -> 우하단 탐색이라 좌표는 자연스럽게 가장 낮은 좌표부터 들어간다.

        // 좋아하는 학생 수가 가장 많은 칸이 단 한가지인 경우, 그것을 우선으로 적용
        if (v_cords.size() == 1)
        {
            pair<int, int> pos = v_cords[0].p;
            map[pos.first][pos.second].student = order_student;
            map[pos.first][pos.second].likes = v_cords[0].likes;
            // update_likes(pos.first, pos.second, order_student);

            continue;
        }

        // 빈 칸이 많은 곳 찾기
        int max_empty_cord = -1;
        // 그 중 행, 열 번호가 가장 낮은 곳
        coord_info min_info;

        for (int i = 0; i < v_cords.size(); ++i)
        {
            // 빈 칸의 수가 더 많은 곳이 발견된다면 거기를 지정해준다.
            if (v_cords[i].emptys > max_empty_cord)
            {
                min_info = v_cords[i];
                max_empty_cord = v_cords[i].emptys;
            }

            // cout << order_student << " -> " << "현재 max empty :" << max_empty_cord << endl;
            // 4가 최대라서 그냥 바로 탈출 해도 됨
            if (v_cords[i].emptys == 4)
                break;
        }

        pair<int, int> pos = min_info.p;

        // cout << "result : " << pos.first << " " << pos.second << endl;
        map[pos.first][pos.second].student = order_student;
        map[pos.first][pos.second].likes = min_info.likes;
        // update_likes(pos.first, pos.second, order_student);
    }

    int sum_score = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            student_info info = map[i][j];
            int like_count = like_counts(i, j, info.student);
            sum_score += score[like_count];
        }
    }

    return sum_score;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            map[i][j] = {-1, 0};
        }
    }

    for (int i = 0; i < n * n; ++i)
    {
        int student;
        cin >> student;

        // 0~20범위로 맞추기 위함
        order[i] = student - 1;

        for (int j = 0; j < 4; ++j)
        {
            int like_student;
            cin >> like_student;
            like[student - 1][like_student - 1] = true;
        }
    }

    cout << seat_down();
}
