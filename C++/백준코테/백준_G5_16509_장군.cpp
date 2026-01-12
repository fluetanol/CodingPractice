#include <iostream>
#include <queue>
using namespace std;


//코끼리 규칙
//장기에서 알던대로
// 1. 한칸을 상하좌우로 움직인다
// 2. 그 다음 두 칸을 그 방향의 대각선으로 움직인다. 
// 3. 가는 중간에 기물이 있다면 그 방향으로는 갈 수 없다.단, 마지막 위치에 기물이 있는 경우 그 놈은 잡히는 기물이니 갈 수 있다.


bool map[10][9] = {};
int move_to[8][2] = { {3,-2}, {3,2},{-3,2},{-3,-2},{2,3},{2,-3},{-2,3},{-2,-3} };

struct answer {
	int count;
	bool flag;
};

bool isRange(int r, int c) {
	return r >= 0 && c >= 0 && r < 10 && c < 9;
}

bool broad_collision_detection(int sr, int sc, int dr, int dc, int kr, int kc) {
	return min(sr, dr) < kr && kr < max(sr, dr) && min(sc, dc) < kc&& kc < max(sc, dc);
}

answer bfs(pair<int, int> e, pair<int, int> k) {
	queue<pair<int, int>> q;
	map[e.first][e.second] = true;
	q.push(e);
	int count = 0;
	bool flag = false;

	while (!q.empty()) {
		int size = q.size();

		for (int s = 0; s < size; ++s) {
			pair<int, int> temp_p = q.front();
			q.pop();
			//cout << temp_p.first << " " << temp_p.second << endl;

			if (temp_p.first == k.first && temp_p.second == k.second) {
				flag = true;
				break;
			}



			for (int i = 0; i < 8; ++i) {
				int r = temp_p.first + move_to[i][0];
				int c = temp_p.second + move_to[i][1];


				//맵 범위 내이고, 아직 한번도 안둘러본 곳이 맞는지
				if (isRange(r, c) && !map[r][c]) {

					bool collision_flag = false;

					//경로상 왕 기물이 있는지
					if (broad_collision_detection(temp_p.first, temp_p.second, r, c, k.first, k.second)) {

						int dr = move_to[i][0];
						int dc = move_to[i][1];
						
						//경로 역추적으로 기물 확인
						for (int a = dr, b = dc; (a != 0 || b != 0);) {
							if (a != 0) a = (dr > 0 ? --a : ++a);
							if (b != 0) b = (dc > 0 ? --b : ++b);
							 

							if (temp_p.first + a == k.first && temp_p.second + b == k.second) {
								collision_flag = true;
								break;
							}

						}
					}

					if (!collision_flag) {
						q.push({ r,c });
						map[r][c] = true;
					}
				}
			}
		}
		if (flag) break;
		count++;
	}


	return { count, flag };
}



int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	pair<int, int> e;
	pair<int, int> k;

	cin >> e.first >> e.second;
	cin >> k.first >> k.second;
	
	answer ans = bfs(e, k);


	cout << (ans.flag ? ans.count : -1);
	
}

/*
    bfs를 이용하면 쉽게 풀리는 문제인데,
    
    문제는 다음 턴에 움직일 동선 안에 왕이 있느냐를 점검하는 것이다. (움직이지 못하는 케이스이므로)

    이를 위해 조금 복잡한 for문을 돌려서 (이동 델타를 조금씩 줄여가며 역추적 하는 방식) 왕이 있는지 점검하는 방식을 썼다.
    
    사실 좀 오버엔지니어링이긴 하지만, brood_collision_detection 충돌 최적화 기법을 써서,
    
    경로상의 직사각 범위내에 왕이 있을 것인가에 대한 후보 도착지만 추리고, 

    그 케이스에 대해서만 경로 역추적을 돌리는 방식으로 최적화를 시도했다.

*/