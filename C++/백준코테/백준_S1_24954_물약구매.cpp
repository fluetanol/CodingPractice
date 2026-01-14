#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

/*
    1. N은 커봐야 10이다.
    2. 할인 정보도 커봐야 10이다.
    3. 할인 가격은 1보다 작아질 수 없다 (즉 아무리 싸게 사도 최소 비용은 N임)


    일단 이건 무조건 해야 하는 로직이다.
    1. 뭔가 하나를 구매하면, 구매한 것에 대해 모든 할인 대상들을 깎아야 한다. 여기에 O(pi)만큼의 부하가 들어감
    2. 문제에서 "구매 순서가 중요함을 깨달았다" 라고 했으므로, 순열로 풀어서 사는 순서의 조합을 따져보는 게 굉장히 중요하다.

    이 때문에 2초도 아니고 3초를 준 이유가 나오는데,
    애초에 조합이면 몰라도 순열은 N!이기 때문에 엄청난 시간 복잡도가 소모된다...


    자료구조는
    1. 포션 가격표가 적혀있는 벡터
    2. 어떤 포션에 대해 할인율이 적혀있는 2차원 벡터
    두개면 충분할듯

    최적화로는 이미 구한 min_cost 보다 지금 계산 중인 cost가 더 커지면 비교가 의미 없으므로
    pruning 시켰다.
    백준에선 최적화 안한게 700ms, 하면 200ms까지 떨어졌다;;
*/

struct set_discount
{
    int num;
    int discount;
};

void discount(vector<int> &v, vector<vector<set_discount>> &p, int choice, bool recovery_flag)
{
    vector<set_discount> discount_v = p[choice];

    if (discount_v.size() == 0)
        return;

    for (int i = 0; i < discount_v.size(); ++i)
    {
        int idx = discount_v[i].num;
        int discount_price = discount_v[i].discount;

        v[idx] += recovery_flag ? discount_price : -discount_price;
    }
}

void perm(vector<int> &v, vector<vector<set_discount>> &p, vector<int> &visited, int depth, int coin, int &min_coin)
{

    if (min_coin < coin)
    {
        return;
    }
    else if (depth == v.size())
    {
        min_coin = min(coin, min_coin);
        return;
    }

    for (int i = 0; i < v.size(); ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            discount(v, p, i, false);
            perm(v, p, visited, depth + 1, v[i] < 1 ? coin + 1 : coin + v[i], min_coin);
            discount(v, p, i, true);
            visited[i] = false;
        }
    }
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> v(n);
    vector<vector<set_discount>> p(n);
    vector<int> visited(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];
    for (int i = 0; i < n; ++i)
    {
        int p_size;
        cin >> p_size;
        p[i] = vector<set_discount>(p_size);

        for (int j = 0; j < p_size; ++j)
        {
            set_discount s;
            cin >> s.num >> s.discount;
            --s.num;
            p[i][j] = s;
        }
    }

    int min = INT_MAX;
    perm(v, p, visited, 0, 0, min);

    cout << min;
}
