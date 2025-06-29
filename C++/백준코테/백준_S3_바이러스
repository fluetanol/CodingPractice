#include <iostream>
#include <vector>
#include <queue>

using namespace std;



int bfs(vector<int>*& arr, int size) {
	queue<int> q;
	int count = -1;
	bool* v = new bool[size + 1]{ false };
	v[1] = true;
	q.push(1);

	while (!q.empty()) {
		int idx = q.front();
		++count;
		q.pop();
		for (int i = 0; i < arr[idx].size(); ++i) {
			int next = arr[idx][i];
			if (!v[next]) {
				v[next] = true;
				q.push(next);
			}
		}

	}
	delete[] v;
	return count;
}

int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	int n, m;
	cin >> n >> m;		//n : 노드갯수, m : 간선갯수

	vector<int>* arr = new vector<int>[n+1];

	for (int i = 0; i < m; i++) {
		int idx= 0, val = 0;
		cin >> idx >> val;
		arr[idx].push_back(val);
		arr[val].push_back(idx);
	}



	int count = bfs(arr, n + 1);
	cout << count;

	delete[] arr;
	
}


/*
    해설

    전형적인 BFS 문제
    인접리스트로 그래프를 입력 받고 이를 bfs 탐색하는데,
    1번 노드와 연결된 모든 이웃 노드들의 갯수만 세주면 된다.

    참고로 엣지리스트의 쌍이 어떻게 들어올지 모르기 때문에 무방향 그래프처럼
    표현하기 위해 양방향으로 노드 정보를 넣어줬다.
    그래서 visited 배열도 따로 만든 모습이다...

*/