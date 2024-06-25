// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2파스칼의삼각형
// 24/04/24
// 30분

#include <iostream>
#include <vector>

using namespace std;

void Pascal(int floor, int n, vector<int> v)
{
    if (floor == n)
        return;
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    vector<int> v2;
    v2.push_back(1);
    while (true)
    {
        int left = v[0];
        v.erase(v.begin());
        if (v.size() == 0)
        {
            v2.push_back(left);
            break;
        }
        else
        {
            int right = v[0];
            v2.push_back(right + left);
        }
    }
    Pascal(floor, n + 1, v2);
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k;
        cin >> k;
        vector<int> v;
        cout << "#" << test_case << endl;
        v.push_back(1);
        Pascal(k, 0, v);
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//BFS로 풀어본 파스칼 삼각형 문제
//1층에선 1이 들어가니 디폴트로 넣어주고,
//그 뒤로는 이런 규칙으로 풀어주면 된다

//1. 다음 층의 큐에도 맨 앞엔 항상 1을 집어넣는다.
//이는 항상 맨 왼쪽은 0(아무것도 없음)+1을 표현하기 위함이다. 수학적 특성임.

//2. 이번 층 큐에 남아있는 원소가 더이상 없게 된다면 맨 마지막에 지운 원소를 다음 층 큐에 넣는다.
//이 또한 오른쪽에 더 없기 때문에 (지운 숫자) + 0의 출력을 표현하기 위함이다.

//3. 큐의 원소가 아직 2개 이상 있다면 좌측 원소가 우측 원소를 더해준다
//방법은 이런 로직으로 한다

/* 
     1) 일단 맨 앞에 있는 좌 숫자를 얻어온다. (left = v[0])
     2) 그리고 그 노드는 이제 써먹었으므로 지운다 v.erase[v.begin()]
     3) 이 때 2번의 조건을 만족하면 2를 수행하고 반복 탈출
     4) 아니라면 3의 조건을 위해 right의 숫자를 얻어온다 (right = v[0], v.erase로 앞서서 지웠기 때문에
     이번 0번방 원소는 바로 그 다음 원소가 나오게 됨)
     5) left+right한 값을 다음 층으로 보낼 큐에 저장해둔다. (v2.push_back(left+right)
*/
