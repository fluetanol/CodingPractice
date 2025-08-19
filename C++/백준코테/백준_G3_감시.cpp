#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int minv = 999999999;

struct vec {
    int x;
    int y;
};


struct cctv {
    vec pos;
    int type;
};


int map[8][8];

//cctv 타입마다 회전 가능한 횟수
int availableRotateCount[] = { 4,2,4,4,1 };
//cctv들
vector<cctv> cctvs;
vector<vector<vec>> typedir(5);
int n, m;
int visited[8];


vec rotate90(vec d) {
    return { -d.y, d.x };
}

vector<vec> rotate90all(vector<vec> d) {
    for (int i = 0; i < d.size(); ++i) {
        d[i]= rotate90(d[i]);
    }
    return d;
}

bool isRange(int x, int y) {
    return (x >= 0 && x < m && y >= 0 && y < n) && map[y][x] != 6;
}


void print() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}



//마킹
void mapping(vector<vec> d, vec pos) {
    vec origin = pos;
    /*        cout << " 시점 " << origin.x << " " << origin.y << " \*/
    for (int i = 0; i < d.size(); ++i) {
        vec v = d[i];
        pos = origin;

        while (isRange(pos.x, pos.y)) {
            if (map[pos.y][pos.x] == 0)
                map[pos.y][pos.x] = 7;
            else if (map[pos.y][pos.x] == 6) {
                break;
            }
            else if (map[pos.y][pos.x] >= 7) {
                map[pos.y][pos.x]++;
            }
            pos.x += v.x;
            pos.y += v.y;
        }
    }
}

//원상 복구
void remapping(vector<vec> d, vec pos) {
    vec origin = pos;
    //print();
    for (int i = 0; i < d.size(); ++i) {
        vec v = d[i];
        //cout << "지우기 방향 : " << " " << v.x << " " << v.y <<  " " << d.size() << "\n";
        pos = origin;
        while (isRange(pos.x, pos.y)) {
            if (map[pos.y][pos.x] == 7)
                map[pos.y][pos.x] = 0;
            else if (map[pos.y][pos.x] == 6) {
                break;
            }
            else if (map[pos.y][pos.x] > 7) {
                map[pos.y][pos.x]--;
            }
            pos.x += v.x;
            pos.y += v.y;
        }
    }
}

void minCounting() {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(map[i][j] == 0)count++;
        }

    }
    minv = min(minv, count);
}

void combination(int depth) {
    //다 둘러봤으면 사각지대 취합
    //cout << depth << " " << cctvs.size() << "\n";
    if (depth == cctvs.size()) {
        minCounting();
        


        return;
    }
 
    int cctvType = cctvs[depth].type;
    vec cctvpos = cctvs[depth].pos;
    vector<vec> cctvdirs = typedir[cctvType];

    //가능한 회전 횟수
    for (int i = 0; i < availableRotateCount[cctvType]; ++i) {
        //매핑
        mapping(cctvdirs, cctvpos);
        visited[depth] = i;
        //cout << "-----------\n";
        //print();
        //cout << "-----------\n";
        //
        //다음 cctv
        combination(depth + 1);

        //원점으로 돌리기
        remapping(cctvdirs, cctvpos);
        //cctv 90도 돌리기
        cctvdirs = rotate90all(cctvdirs);
    }
}


int main()
{
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    typedir[0].push_back(vec{ 1,0 });

    typedir[1].push_back(vec{ 1,0 });
    typedir[1].push_back(vec{ -1,0 });
    
    typedir[2].push_back(vec{ 1,0 });
    typedir[2].push_back(vec{ 0,1 });
    
    typedir[3].push_back(vec{ 0,1 });
    typedir[3].push_back(vec{ 1,0 });
    typedir[3].push_back(vec{ 0,-1 });
    
    typedir[4].push_back(vec{ 0,1 });
    typedir[4].push_back(vec{ 1,0 });
    typedir[4].push_back(vec{ 0,-1 });
    typedir[4].push_back(vec{ -1, 0 });

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
            if (map[i][j] >= 1 && map[i][j] <= 5) {
                cctv c{ vec{j, i}, map[i][j] - 1 };
                cctvs.push_back(c);
            }
        }
    }

    combination(0);

    cout << minv;


}



//백트래킹 완탐 문제였는듯
//각 cctv 케이스별로 가능 회전수와 감시 방향을 미리 전처리하고
//그냥 문제 요구 대로 완탐 때려서 푼 문제였다

// 빡센 부분 1. 감시 처리 영역을 되돌리는 remapping 작업
// 지금 보면 7로 매핑할거 없이 -1씩 증가 시키고 다시 +1로 되돌리는 방식을 쓰는 게 더 좋았을듯

// 빡센 부분 2. mapping 시 pos.x, pos.y (시작지점)을 포함하지 않고 푼 문제
//왜인지는 모르겠는데 포함을 안시키니까 벽으로 둘러 쌓인 곳도 매핑을 시키는 문제가 생겼다.
// 0 0 0 6 6
// 0 3 0 6 0
// 0 0 0 6 6
// 이런 케이스