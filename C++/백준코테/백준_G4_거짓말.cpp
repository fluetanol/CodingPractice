// 문제번호 : 1043번
// 거짓말
// 푼 시간 : 40분
// 알고리즘 분류 : BFS (내가 푼 방식), Union Find(권장 방식), 그래프 탐색
//  권장하는 백준 알고리즘 분류 :그래프 탐색, 분리 집합

#include <iostream>
#include <vector>

using namespace std;

void BFS(vector<vector<int>> &party, vector<int> truth, vector<int> partyq)
{
    while (!partyq.empty())
    {
        int trueperson = partyq.front();

        // trueperson이 껴있는 모든 파티 찾기
        for (int i = 0; i < party.size(); i++)
        {
            bool canLie = true;

            for (int j = 0; j < party[i].size(); j++)
            {
                // 한 놈이라도 true person이 존재하면 여기는 이제 구라 못치는 파티임
                if (trueperson == party[i][j] && canLie)
                {
                    j = -1;
                    canLie = false;
                }

                // 구라 못치는 파티에 있는 모든 애들은 앞으로 그냥 구라 못치는 애들임
                // 그 놈들 목록 만들어둠
                else if (trueperson != party[i][j] && !canLie)
                {
                    partyq.push_back(party[i][j]);
                }
            }
            // 어차피 앞으로 다시 둘러봤자 여긴 구라 못치는 파티인거 확정이니까
            // 이제 신경 안쓸거임
            if (!canLie)
            {
                party.erase(party.begin() + i);
                i--;
            }
        }

        partyq.erase(partyq.begin());
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;
    vector<int> truth(n + 1);
    vector<int> partyq(k);

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        truth[num] = 1;
        partyq[i] = num;
    }

    vector<vector<int>> party(m);
    for (int i = 0; i < m; i++)
    {
        cin >> k;
        vector<int> person(k);
        party[i] = person;
        for (int j = 0; j < k; j++)
            cin >> party[i][j];
    }

    BFS(party, truth, partyq);
    cout << party.size();
}


/*
    N, M 주어진 입려값이 50이하라서 완탐을 해도 문제는 없었는데,
    사실 이런 큐를 이용한 BFS보다 더 나은 방법이 있으니, 바로 분리집합이다.

*/


int findParent(vector<int> &parent, int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent, parent[x]);
}

void unionParent(vector<int> &parent, int a, int b)
{
    a = findParent(parent, a);
    b = findParent(parent, b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int k;
    cin >> k;
    vector<int> truth(k);
    for (int i = 0; i < k; i++)
    {
        cin >> truth[i];
    }

    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++)
    {
        int num;
        cin >> num;
        parties[i].resize(num);
        for (int j = 0; j < num; j++)
        {
            cin >> parties[i][j];
        }
        for (int j = 1; j < num; j++)
        {
            unionParent(parent, parties[i][0], parties[i][j]);
        }
    }

    vector<bool> canLie(m, true);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if (findParent(parent, parties[i][0]) == findParent(parent, truth[j]))
            {
                canLie[i] = false;
                break;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++)
    {
        if (canLie[i])
            count++;
    }

    cout << count;
}



//쉽게 설명하면 거짓말을 못치는 집합들을 따로 묶어 두어 해당 번호 사람이 거짓말 칠수 있는 지 없는지를 판가름 한다.
//일종의 부분집합을 만드는 방식인데, 당연히 일정한 규칙에 따라 만들어야 그 집합내에 있는지 없는지 판가름하기도 쉬울 것이다.

/*
    위 방식에서의 집합 구성 방식을 보면


    Ex)
    8 5
    3 1 2 6
    3 1 2 8
    4 3 7 4
    2 8 7
    2 5 6
    1 5

    이라고 하자.
    위 방식은 각 파티의 무조건 첫번째 원소를 기준으로 집합 연결관계를 만든다.
    더 큰놈이 아래로, 작은놈이 위로 가게 하는 (깊이 비례) 오름차순을 택하고 있음
    이 때 반드시 연결은 최상단 부모(root)에 연결시킨다.

    3 1 2 8의 경우 ->   1 -> 2
                       1 -> 8
    set 1 최상단 노드  = 1

    3 1 2 6의 경우 ->   1 -> 2
                        1 -> 6
    set 2 최상단 노드  = 1
    그런데 set1, set2둘다 최상단 노드가 1이므로 사실상 같은 집합이라고 보면 된다, 즉.

    1의 자식원소는 2, 6, 8. 계속 가보자

    4 3 7 4의 경우 ->   3 -> 7
                        3 -> 4
    set3 최상단 노드 = 3
    3의 자식원소는 4, 7
    이건 앞선 set1과 루트노드가 다르므로 또 다른 집합이긴 함.

    2 8 7의 경우 ->    7 -> 8.
    그런데 여기서 7의 최상단 노드는 3, 8의 최상단 노드는 1이다.
    위의 대소법칙 비교를 통해 질서를 만든다면,

    1 -> 3이 되어야 하는 게 맞다.
    즉, 1->8은 유지되고,
    1 -> 3 -> 7로 연결된다는 것.

    정리하면
    1 -> 2, 6 ,8
    1 -> 3 -> 7,4

    이렇게 합쳐진 집합이 된다

    마지막은 5하나 남았는데, 5는 무조건 자기 자신이 최상단 노드가 된다.


    즉, 두 집합이 만들어진다.
    1. 1을 루트로 하는 집합
    2. 5를 루트로 하는 집합

    여기서 1은 진실을 알고 있는 사람이므로, 1이 속한 집합은 거짓말을 칠 수 없는 집합이다.
    따라서 1이 속한 집합에 속한 파티는 거짓말을 칠 수 없다.
    그런데, 이 거짓말을 친 집합의 애들은 그 집합의 어느 원소를 고르든 parent를 따라가면 결국
    무조건 1을 출력하게 된다. 즉,



    거짓말을 못치는 애들, 1 2 6과
    어떤 파티의 첫번쨰 원소랑만 비교해서 만약 루트 원소가 단 한번이라도 같은 경우가 생긴다면,
    그 파티의 친구들은 전부 진실을 알고 있는 사람의 집합에 속해있다는 것이므로
    거짓말을 못친다고 보고,

    만약 단 한번도 겹치지 않는다면 구라를 쳐도 되는 집합으로 치면 된다.

    즉, 위 예시에선 1,2,3,4번째 파티 모두 거짓말이 안되고, 마지막 파티만 거짓말이 가능하다.

    {
        진실 쟁이 : 1 2 6
        - (1,2 8)의 첫번째 원소 1과 1의 루트 원소 비교  = 1로 같음, 같은 진실쟁이 집합이므로 바로 거름

        - (3,7,4)의 첫번째 원소 3과 1의 루트 원소 비교 = 1로 같음 . 같은 진실쟁이 집합

        - (8 7)의 첫번쨰 원소 8과 1의 루트 원소 비교 = 1로 같음 같은 진실쟁이 집합.

        - (5)의 첫번쨰 원소 5와 1의 루트 원소 비교 -> 5와 1로 서로 다름. 그 다음!
            원소 5와 2의 루트 원소 비교 => 5와 1로 서로 다름, 그 다음!
            원소 5와 6의 루트 원소 비교 => 5와 1로 서로 다름,

        따라서 5는 거짓말 쳐도 되는 집합에 속함.
    }


    이런 식으로 전체를 둘러볼 필요 없이, 부분의 연관 관계를 합쳐 빠르게 상황 파악과 검색을 하는
    알고리즘을 분리 집합 (union find)라고 한다.

    이 알고리즘이 특히 잘 쓰이는 경우가 sns 네트워킹인데,
    수많은 사람들이 그래프로 연결되어있는 sns에서는 
    전체 탐색으로 추천 친구나, 가까운 친구를 찾아주는 서비스를 운영하는 건 성능적으로 정말 큰 문제가 생긴다.
    내 친구가 100명인데 1500명 있는 계정과 친구를 맺기 시작하면 100명과 1500명 전부를 연결하고 하는 건 너무 복잡하다는 것.

    따라서 나와 연결된 친구 관계, 그리고 상대와 연결된 친구관계를 전부 맺지 않고
    루트 노드인 나와 친구를 맺으려는 상대 노드랑만 연결이 되면 (집합 union)
    내가 상대의 친구를 확인하려고 할때  내 노드 -> 상대 노드 -> 상대 친구노드 딱 두단계만 거쳐 가면 누구든지 볼 수 있게 된다.(find)

    알아두면 정말 좋을 그래프 알고리즘...
    게임에서도 충분히 쓰일 수 있다고 생각함.
    
*/
