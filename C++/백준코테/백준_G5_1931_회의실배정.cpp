// 알고리즘 분류 : 메모이제이션 + dfs(백트래킹)
// 최고 효율 : 그리디
// 백준_1931

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


struct schedule {
    int s;
    int e;
    int c;

    bool operator<(schedule other)const {

        if (s != other.s)
            return s < other.s;
        else
            return e < other.e;
    }
    
};


int DFS(vector<schedule>& v, int idx, int finish) {
    //이미 기록되었다면 그거 반환
    if (v[idx].c > 0) return v[idx].c;

    int start = v[idx].s;
    int end = v[idx].e;

    bool visited = false;
    for (int i = idx+1; i < v.size(); ++i) {
        if (i != idx && end < v[i].s) {
            visited = true;
            v[idx].c = max(DFS(v, i, finish) + 1, v[idx].c);
        }
    }

    //끝 점
    if (!visited) {
        v[idx].c = 1;
    }

    return v[idx].c;
    
    /*
        1. end == finish 인 경우 -> 1을 반환
        2. 배열 끝까지 갔지만 아무것도 visit을 못한 경우 -> 그냥 그게 끝이므로
        그것도 1 반환
    */
}

int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<schedule> v(n);
    

    int finish = -1;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = { a,b , 0};
        if (finish < b) finish = b;
    }

    sort(v.begin(), v.end());

    int maxv = -1;
    for (int i = 0; i < n; ++i) {
        maxv = max(DFS(v, i, finish), maxv);
    }

    cout << maxv;
}

//위 방법도 나쁘지 않지만 n이 100000이기 때문에 제곱수로 늘어나는 dfs 특성상 메모이제이션 만으로는 해결이 안되는 수준의 부하가 들어간다.





// 그리디 풀이법

//어차피 종료 시간에 따라 다음에 무엇이 와야 할 지에 대한 일정들이 결정된다.
//따라서 종료 시간이 가장 낮은 것 부터 꽉꽉 채워넣는 게 좋다.
//GPT가 기막힌 비유를 들어줬는데
//자리 눈치 싸움 할 때 곧 내릴것 같은 놈 앞에 서서 기다리지,
//한참 나중에 내릴것 같은 놈 앞에 서서 기다리진 않는다.
//이 사실은 시작 시간 (자리를 앉은 시간, 문제에선 회의 시작 시간)이 그리디한 선택에 중요성이 없음을 보여준다.

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


struct schedule {
    int s;
    int e;

    bool operator<(const schedule& other) const {
        if (e == other.e) return s < other.s; // 끝나는 시간 같으면 시작 시간 빠른 걸 앞으로
        return e < other.e;
    }
    
};


int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<schedule> v(n);
    

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v[i] = { a,b};
    }

    sort(v.begin(), v.end());

    int count = 0;
    int end_time = 0;
    for (int i = 0; i < n; ++i) {
        int new_start = v[i].s;
        int new_end = v[i].e;

        if (end_time <= new_start) {
            ++count;
            end_time = new_end;
        }
    }
    cout << count;
}

