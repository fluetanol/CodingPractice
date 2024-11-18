// 삼성아카데미d4상자정렬하기
// 문제 유형 : 정렬, 구현


#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int k;
        cin >> k;

        vector<int> v(k + 1);
        vector<int> nset(k + 1);

        v[k] = 0;    // 0은 그냥 빈칸의 의미
        nset[0] = k; // 빈칸의 위치는 처음에 맨 끝에 있다.

        for (int i = 0; i < k; i++)
        {
            cin >> v[i];
            nset[v[i]] = i;
        }

        int count = 0;
        int idx = 0;
        vector<int> note;
        while (idx < k)
        {
            if (v[idx] != idx + 1 && v[idx] != 0)
            {
                int val = v[idx];
                note.push_back(idx + 1);
                swap(v[idx], v[nset[0]]);
                swap(nset[val], nset[0]);
                count++;
            }
            if (v[idx] == 0)
            {
                int val = v[nset[idx + 1]];
                note.push_back(nset[idx + 1] + 1);

                swap(v[idx], v[nset[idx + 1]]);
                swap(nset[0], nset[val]);
                count++;
            }
            idx++;
        }
        cout << count << "\n";
        for (int i = 0; i < note.size(); i++)
        {
            cout << note[i] << " ";
        }
        cout << "\n";
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

/*
    심플하게 i=0부터 k-1까지 돌면서 다음 과정을 확인해보면 된다.

    1. v[i] == i 라면 넘어감

    2. v[i] != i 라면, 
        1) 해당 v[i]를 비워두고
        2) v[i]의 위치에 i를 갖다 넣는다.

    예를 들어서 2 3 1 4 0 이라고 해보자. 0은 비워져있다는 뜻임.
    인덱스는 편의상 1부터 시작한다고 가정하면

    v[1] == 1이여야 하지만, 2이므로 우선 빈칸과 교환한다.
    
    0 3 1 4 2

    그 다음 비워진 첫번째 칸에 1과 교환한다.

    1 3 0 4 2

    이 과정이 반복되는 데, 만약 우연히도 i번째 칸이 이미 0이라면, 그냥 i가 있는 칸과 교환하면 된다.


이런 주기가 반복되기 때문에 사실 한번의 숫자를 바꾸는 것은 최대 두번의 교환을 필요로 하게 된다.

성능은 O(n)이다.
*/