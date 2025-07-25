#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct pos {
    int x;
    int y;
};

int delta[][2] = { {1,0},{0,1},{-1,0},{0,-1} };

bool isRange(int ddx, int ddy, int size) {
    return ddx >= 0 && ddx < size && ddy >= 0 && ddy < size;
}


//2667 단지번호 붙이기
void bfs(string*& arr, pos p, int size, vector<int>& counts) {
    queue<pos> q;
    arr[p.y][p.x] = '0';
    q.push(p);
    int count = 0;

    while (!q.empty()) {
        pos newp = q.front();
        q.pop();
        count++;
        int x = newp.x;
        int y = newp.y;

        for (int i = 0; i < 4; ++i) {
            int dx = delta[i][1];
            int dy = delta[i][0];

            int ddx = x + dx;
            int ddy = y + dy;
            if (isRange(ddx, ddy, size) && arr[ddy][ddx] == '1') {
                arr[ddy][ddx] = '0';
                q.push({ ddx, ddy });
            }
        }
    }

    counts.push_back(count);


}


int main()
{
    cin.tie(0);
    cout.tie(0);

    size_t n;
    cin >> n;
    vector<int> counts;

    string* arr = new string[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    size_t count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == '1') {
                bfs(arr, { j, i }, n, counts);
                ++count;
            }
        }
    }

    cout << count << "\n";
    sort(counts.begin(), counts.end());
    for (int i = 0; i < counts.size(); i++) {
        cout << counts[i] << "\n";
    }

}

