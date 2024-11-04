// 문제번호 : 2293번
// 동전1
// 푼 시간 : 1시간
// 알고리즘 분류 : DP

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }

    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(k + 1);
    }

    for (int j = 0; j < k + 1; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int val = vec[i];

            // 값 보다 크면 무시
            if (j < val)
                v[i][j] = 0;
            // 값과 같으면 하나
            else if (j == val)
                v[i][j] = 1;

            else
            {
                for (int l = 0; l <= i; l++)
                {
                    v[i][j] += v[l][j - val];
                }
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += v[i][k];
    cout << sum << endl;
}


/*
    DP로 푸는 문제인데, 위 방법이 틀린건 아니지만 무려 메모리 제한에서 걸렸다...
    2차원 배열말고 1차원 배열로 푸는 방법이 있다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



int main(int argc, char const* argv[]) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n, k;
	cin >> n >> k;

	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> v(k + 1);
	v[0] = 1;
	for (int i = 0; i < n; i++) {
		int pick = arr[i];
		for (int j = pick; j <= k; j++) {
			v[j] = v[j] + v[j - pick];
		}
	}
	delete[] arr;

	cout << v[k] << endl;
}


/*
    요지는 간단한데, 
    총합 a일 때 각 동전을 사용하는 경우의 수를 미리 구하는 게 아니라,

    가장 낮은 동전을 사용하는 경우에 총합 a를 만들기 위해 필요한 경우의 수 ->
    그 다음 낮은 동전을 같이 사용하는 경우 총합 a를 만들기 위해 필요한 경우의 수 -> ....
    이런 식으로 누적합을 구하는 건데, 이렇게 하면 다음과 같은 규칙을 볼 수 있다.

    ex) 1, 2, 5
    0 1 2 3 4 5 6 7 8 9 10
    1 0 0 0 0 0 0 0 0 0 0 
    (0인 경우는 모든 동전을 사용안하는 경우의 수로 1이 있음)

    1원만 사용할 시
    v[1] += v[1 - 1] = 1
    v[2] += v[2 - 1] = 1
    v[3] += v[3 - 1] = 1
    v[4] += v[4 - 1] = 1
    ...

    0 1 2 3 4 5 6 7 8 9 10
    1 1 1 1 1 1 1 1 1 1 1 

    1, 2원 사용할 시
    v[1]은 2원보다 작기 때문에 더이상 업데이트 할 부분이 없다.대신,
    v[2] += v[2 - 2] => 1 + 1 = 2
    v[3] += v[3 - 2] = 2
    v[4] += v[4 - 2] = 3
    ...

    0 1 2 3 4 5 6 7 8 9 10
    1 1 2 2 3 3 4 4 5 5 6

    이런식으로, 한번의 주기마다 더 낮은 k원을 함께 사용했을때의 경우의 수를 누적시키는 방법이다.
    이러면 공간 복잡도도 O(k)로 줄어들고, 시간복잡도도 O(nk)로 줄어든다.
    점화식을 요약하면

    v[j] += v[j - pick] (pick은 현재 사용이 허용된 동전의 가치이다)  

*/