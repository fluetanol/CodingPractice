#include <iostream>
#include <map>
using namespace std;

int n, m, b;
int countTime;

map<int, int> mp;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> b;
    n *= m;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        mp[m]++;
    }

    while (true)
    {
        auto low = mp.begin();
        auto high = mp.rbegin();

        if ((low->first) == (high->first))
            break;

        int build = low->second;
        int dig = 2 * (high->second);

        if (b >= low->second && build <= dig)
        {
            b -= low->second;
            countTime += build;
            mp[low->first + 1] += low->second;
            mp.erase(low->first);
        }
        else
        {
            b += high->second;
            countTime += dig;
            mp[high->first - 1] += high->second;
            mp.erase(high->first);
        }
    }

    cout << countTime << " " << mp.begin()->first;
}

// local greedy 방식으로 푼 방법으로 성능도 기존의 브루트포스보다 낫다

/*
    방법은 이렇다.

    1. 각 높이가 몇 칸씩 있는지 map을 통해 저장한다
    2.  가장 높은 지형을 낮추는 것과, 가장 낮은 지형을 높히는 것 중 무엇이 더 나은가를 따진다
        - 이 때 높히는 경우, 인벤토리의 블럭이 충분한지를 확인해야한다.
    3. 더 나은 쪽을 택하여 반복한 뒤, 더 이상 높낮이가 다르지 않으면 종료한다.

    이 방법이 맞는 이유는 gpt한테 물어보니 convex optimization 문제라서 그렇다고 하는데,

    convex optimization 이란
    "볼록 함수의 최적화 문제를 다루는 수학적 최적화의 한 분야로, 전역 최적해를 효율적으로 찾을 수 있는 문제들을 포함한다."

    말이 어려운데 쉽게 설명하면, 간혹 비용함수가 록한 형태, 2차 계수가 양수인 (0아님) 2차함수 형태로 나타나는 경우를 생각해보자.
    이런 경우 결국 함수의 중간 지점이 가장 낮고, 왼쪽과 오른쪽으로 갈 수록 비용이 증가하는 형태가 된다. (u자 형태)
    그리고 이러한 볼록함수의 특성은
    
    "어떤 지역 최솟값(local minimum)도 곧 전역 최솟값(global minimum)"

    이라는 특성이 증명되어있다.
    그럼 이 문제의 특성을 보자, 높이를 평탄화 할 떄의 비용함수를 cost(h)라고 하면

    
    cost(h) = lower_cost(h) + higher_cost(h)
    (lower_cost(h) : h보다 낮은 지형을 높히는 비용 함수
    (higher_cost(h) : h보다 높은 지형을 낮추는 비용 함수

    이때 낮은 지형을 높히면 1의 비용이, 높은 지형을 낮추면 2의 비용이 드는데, 
    모든 지형을 낮추려고 한다면 높은 지형에서 낮추는 2배의 비용이 장난 아니고,
    모든 지형을 높히려고 하면 최대 높이의 지형을 제외한 다른 모든 낮은 지형의 높이를 맞추는 데의 비용이 높아진다.
    그렇다면, 어디 애매한 중간의 h를 찾는다면, 높은 지형이 낮추는데의 비용이 줄어들고, 낮은 지형을 높히는 비용도 줄어들지 않을까?
    이 때문에 cost(h)가 왼쪽(낮은 h)과 오른쪽(높은 h)으로 갈 수록 비용이 증가하고, 어느 중간지점에선 최소값이 되는 볼록함수가 될 것임을
    유추할 수 있는 것이다.

    따라서, 이 문제는 convex optimization 문제이며, 그 특성에 의해 greedy한 방법으로 풀어도 정답이 된다는 것이다.

    */