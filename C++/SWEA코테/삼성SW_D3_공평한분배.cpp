// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3공평한분배
// 24/05/03
// 1시간

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, k;
        cin >> n >> k;
        int *candy = new int[n];
        for (int i = 0; i < n; i++)
            cin >> candy[i];
        sort(candy, candy + n);

        int min = 999999999;
        for (int i = 0; i < n - k + 1; i++)
        {
            int v = candy[i + (k - 1)] - candy[i];
            if (min > v)
                min = v;
        }
        cout << "#" << test_case << " " << min << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}



//처음에는 순열로 풀었는데 시간초과가 나버렸다
//그니까 결국 수학으로 풀으라는 문제였다..
//참고로 순열로 풀면 순열 함수는 다음과 같다
/*
int combination(int n, int k, int* candy, int idx, vector<int> v){
    v.push_back(candy[idx]);
    if(v.size() == k) return v[v.size()-1] - v[0];
    int min = 999999999;
    for(int i=idx+1; i<n; i++){
        int temp = combination(n, k, candy, i, v);
        if(min> temp) min = temp;
    }
    return min; 
}
참고로 시간복잡도가 어마어마함
*/

//일단 주어진 입력값을 정렬해보면 정답이 나온다.
//예를 들어 1 3 4 8 11 12 로 정렬했다고 쳐보자
//만약 k=3이라면 무조건 인접해 있는 세개의 수를 고르는게 가장 효율이 좋음을
//알 수 있다
//왜냐면 크기 순으로 정렬이 되었으므로 고르는 세가지 수의 격차가 커질수록
//큰 수와 작은 수의 격차도 점점 커지는게 자명하기 때문이다.

//결론은 k개의 수를 고를 때 정렬된 인접 인덱스의 수 k개를 고르고,
//가장 처음에 고른 수가 가장 작은 수, 가장 마지막에 고른 수가 가장 큰 수라는게
//자명하므로, 인덱스 연산을 통해 두 수간의 차이를 구하고
//그 차이들 중 가장 작은 놈을 그냥 출력시키면 된다.