#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int toPos(int w, int h, int dir, int offset)
{
    // 기준: 북서(좌상) 코너에서 시계방향으로 이동한 거리
    if (dir == 1)
    { // 북
        return offset;
    }
    else if (dir == 4)
    { // 동
        return w + offset;
    }
    else if (dir == 2)
    { // 남
        return w + h + (w - offset);
    }
    else
    { // dir == 3 서
        return 2 * w + h + (h - offset);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, n;
    cin >> w >> h >> n;

    vector<int> stores;
    stores.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int dir, offset;
        cin >> dir >> offset;
        stores.push_back(toPos(w, h, dir, offset));
    }

    int gdir, goffset;
    cin >> gdir >> goffset;
    int me = toPos(w, h, gdir, goffset);

    int P = 2 * (w + h);
    int sum = 0;

    for (int s : stores)
    {
        int d = abs(me - s);
        sum += min(d, P - d);
    }

    cout << sum << "\n";
    return 0;
}

/*
    참조 링크 :gpt 풀이 - https://chatgpt.com/share/6970f81b-ca24-8002-ac93-4f5d68720ee8

    내 풀이가 2차원 둘레 시뮬레이션이였다면, 이건 둘레를 1차원 선분으로 생각한 풀이이다.
    북, 동, 남, 서 방향에 따라 1차원 상의 좌표로 변환한 뒤
    각 상점과의 거리를 구하는 방식이다.

    1차원으로 변환하는 방식이 매우 깔끔하다.
    2차원으로 구현했을 때는 회전까지 고려해야해서 틀릴 확률이 너무 높은게 문제.

*/