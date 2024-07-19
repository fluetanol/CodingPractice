// 문제번호 : 1025
// 제곱수찾기
// 푼 시간 : 4시간...
// 알고리즘 분류 : 완전탐색

#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>
#include <unordered_map>
#pragma warning(disable : 4996)

using namespace std;

bool isSquare(long num)
{
    long root = sqrt(num);
    return root * root == num;
}

long stringCat(vector<string> &v, int n, int m, int i, int j, long maxsquare)
{
    string s = "";
    long maxs = maxsquare;
    if (i == 0 && j == 0)
    {
        s += v[n][m];
        if (isSquare(stol(s)))
        {
            maxs = max(maxs, stol(s));
        }
        return maxs;
    }
    int a = n, b = m;
    while (a < v.size() && b < v[0].size() && a >= 0 && b >= 0)
    {
        s += v[a][b];
        long num = stol(s);
        if (isSquare(num))
        {
            maxs = max(maxs, num);
        }
        a += i;
        b += j;
    }
    return maxs;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    long maxsquare = -1;
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {
            //-n -> 뒤로 가겠다 +n -> 앞으로 가겠다
            // 상, 하 ,좌, 우 방향 전부 싹다 둘러보기 위해 하는 행동
            for (int i = -n; i < n; i++)
            {
                for (int j = -m; j < m; j++)
                {
                    maxsquare = stringCat(v, x, y, i, j, maxsquare);
                }
            }
        }
    }
    cout << maxsquare;
}

//엄청 헤맨 이유

/*
    만악의 근원은 저 sqrt체크 연산에 있었는데,
    isSquare(long num) 즉, 완전제곱수인지 확인해야하는 타이밍을 더 촘촘히 해야했었다.
    
    나의 경우엔 stringCat이 한번 완전히 돌고 난 뒤 얻어낸 문자열을 기준으로 isSquare을 확인했는데
    무슨 테스트케이스에서 걸려 넘어진건지 진짜 모르겠어도
    이 방법으로 했을 때 while문에서 문자열이 조립되는 과정에서 얻어낸 
    어떤 부분 문자열이 더 큰 완전 제곱수를 갖게 되는 케이스가 있던것 같다.   
    
    
    물론 이전 방식(아래에 코드 넣음)은 dx, dy를 위한 인덱싱과 문자열 조립과정이 좀 중구난방한 문제가 있긴 한데
    그렇다고 완전 탐색에 대한 문제 자체는 없었다.
    아무리 봐도 "더 큰 완전제곱수를 찾는 타이밍"을 더 촘촘히 하지 않은 문제가 컸던것 같다.
    실제 정답코드랑 비교 해 봤을때도 유일한 로직 차이가
    완전제곱수 판정코드가 while문 문자 조립과정에 있냐 아니면 문자열을 완전 조립한 후에 하냐 차이였음

    이래서 브루트 포스 문제는 사람 얼빠지게 하는 뭔가가 있어서 싫음

    아래 코드는 갈아엎기 전 틀렸던 코드.
*/


using namespace std;

vector<string> stringCat(vector<string> &v, int n, int m, int i, int j)
{
    vector<string> vs;

    string s = "";
    if (i == 0 && j == 0)
    {
        s += v[n][m];
        vs.push_back(s);
        return vs;
    }

    s.reserve(v[0].size());
    int a = n;
    int b = m;

    //왼쪽 위에서 오른쪽 아래로 가는 방향. 여기 while문 문자열 조립 한번할때마다 그 문자열에 대해 완전제곱수를 체크해줬어야 했다는 끔찍한 이야기.
    while (a < v.size() && b < v[0].size())
    {
        s += v[a][b];
       
        //그니까 이 사이에 s가 완전제곱수인지, 그리고 그게 maxsquare보다 큰지 확인해줘야 했음.

        a += i;
        b += j;
    }
    vs.push_back(s);
    reverse(s.begin(), s.end());
    vs.push_back(s);

    a = n;
    b = m;
    s = "";
    s.reserve(v[0].size());

    while (a < v.size() && b >= 0)
    {
        s += v[a][b];

        //여기도 마찬가지
        
        a += i;
        b -= j;
    }

    if (s.size() > 1)
    {
        vs.push_back(s);
        reverse(s.begin(), s.end());
        vs.push_back(s);
    }

    return vs;
}
//다만 위의 stringcat은 성능에는 문제가 없을 지언정 
//동작의 이해와 코드의 직관성은 진짜 너무 구리기 때문에, 갈아 엎은 버전 (-n~n으로 상하좌우 조절)
//의 코드를 공부하는게 더 좋을 듯 하다.



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    string s = "";
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int maxsquare = -1;
    for (int k = 0; k < n; k++)
    {
        for (int h = 0; h < m; h++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {

                    //그런데 여기에서 보면 알 수 있듯 완전히 조립된 문자열만을 완전제곱수 판정 데이터라고 생각했음
                    //하 이거 문제를 제대로 안읽은게 문제였던건가
                    vector<string> vs = stringCat(v, k, h, i, j);

                    //더 큰 완전제곱수 판정
                    for (int l = 0; l < vs.size(); l++)
                    {
                        s = vs[l];
                        int k = stoi(s);
                        int root = sqrt(k);
                        if (root * root == k)
                            maxsquare = max(maxsquare, k);
                    }


                }
            }
        }
    }
    cout << maxsquare;
}
