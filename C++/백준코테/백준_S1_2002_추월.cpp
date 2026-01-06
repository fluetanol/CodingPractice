#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/*

    0번 인덱스부터

    1. 원본 문자열이 비교군 문자열의 몇번째에 있는지 찾는다
    2. 찾았으면 자기 앞에 있는 모든 문자열은 set에 저장해두고, 그 문자열의 수 만큼 count 한다.
    3. 원본 문자열이 다음 인덱스로 넘어간다.
    4. 다음 인덱스 문자열이 set에 이미 있다면 그냥 넘어가고, 아니라면 다시 어디에 있는지 찾아본다. 이 때,
        자기 앞자리에 있던 문자열을 찾은 위치부터 검색해 나가면 된다.
    5. 마찬가지로 set에 집어 넣으며 또 count를 증가시킨다.
    6. 원본 인덱스의 마지막에 도달할 때 까지 반복한다.


    이게 되는 이유는 "어떤 상황이 반드시 더 앞지른 차량인가"를 고민해봐야 아는데, 예를 들어 이런 상황을 보자

    a b c d
    b c d a

    얼핏 보면 a만 앞질렀으니 뭐 한 대만 추월했나 싶을 건데, 여기선 추월 당한 차가 a인거지 추월한 차가 a가 아니다.
    가장 앞에 있는 a를 b, c, d 모두가 앞질러서 a보다 먼저 나온 상황이니 3대가 추월한 셈인거다. 다시 이번엔 이런 케이스를 보자

    a b c d
    a c d b

    이것도 보면 이번엔 b를 c, d 가 앞질렀다는 걸 알 수 있다.

    그러니까 다시 말해, 가장 앞에 있는 차량이 얼마나 뒷 놈에게 추월 당했냐를 점검해봐야 한다는 것이다.
    만약 적게 추월 당했다? 그럼 그 다음으로 들어간 차량은 얼마나 추월 당했는지. 또 그 다음 차량은 얼마나 추월 당했는지 따져보면 된다는 것이다.

    이미 더 앞차를 추월해버린 차들은 신경쓸 필요가 없다. 왜냐면 이새끼들은 이미 다른 모든 뒷 차들을 앞질렀다는 거니까.
    그래서 그 이미 추월해버린 차들을 신경 안쓰기 위해 set에 저장해둔 것이다.

    그리고 추월 당한 차의 위치를 발견했다면, 당연히 아직 발견 안된 추월 당한 차들은 그 뒤에 있을 것이므로 (왜냐면 추월을 하지 않았기 때문에
    원래 순서보다 무조건 뒤에 있을 수 밖에 없다.) 그 다음 탐색은 그 위치에서부터 시작하면 된다.
    따라서 코드 내에서도 last_idx를 이용하여 그 위치를 캐싱해둔것이다.


    얼핏보면 O(N^2) 처럼 보이지만, 실제로는 set에 저장된 문자열들은 다시 탐색하지 않기 때문에
    전체 시간 복잡도는 O(N)이 된다. (물론 set의 저장과 탐색은 이상적인 O(1)보단 물리적으론 좀 느림)

*/

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<string> v_org(n);
    vector<string> v_cmp(n);
    unordered_set<string> us;

    for (int i = 0; i < n; ++i)
    {
        cin >> v_org[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> v_cmp[i];
    }

    int count = 0;
    int last_idx = 0;

    for (int i = 0; i < n; ++i)
    {
        string origin = v_org[i];

        if (us.find(origin) != us.end())
        {
            continue;
        }

        for (int j = last_idx; j < n; ++j)
        {
            string compare = v_cmp[j];

            if (origin == compare)
            {
                last_idx = j + 1;
                break;
            }
            else
            {
                us.insert(compare);
                count++;
            }
        }
    }

    cout << count;
}

