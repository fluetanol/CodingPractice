// 문제번호 : 3085
// 사탕게임
// 푼 시간 : 3시간
// 알고리즘 분류 : 브루트포스

#include <iostream>
#include <vector>

using namespace std;

int maxValue(vector<string> &v, int i, int size, bool isColumn)
{
    char c = isColumn ? v[i][0] : v[0][i];
    int maxv = -1;
    int count = 0;

    for (int j = 0; j < size; j++)
    {
        if (isColumn && c == v[i][j] || !isColumn && c == v[j][i])
            count++;
        else if (isColumn && c != v[i][j] || !isColumn && c != v[j][i])
        {
            maxv = max(maxv, count);
            c = isColumn ? v[i][j] : v[j][i];
            count = 1;
        }
    }
    maxv = max(maxv, count);
    return maxv;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    vector<string> v(t);
    for (int i = 0; i < t; i++)
        cin >> v[i];
    int maxv = -1;

    for (int i = 0; i < t; i++)
    {
        maxv = max(maxv, maxValue(v, i, t, true));
        maxv = max(maxv, maxValue(v, i, t, false));
        for (int j = 0; j < t; j++)
        {
            char c = v[i][j];
            if (j < t - 1 && c != v[i][j + 1])
            {
                swap(v[i][j], v[i][j + 1]);
                maxv = max(maxv, maxValue(v, i, t, true));
                maxv = max(maxv, maxValue(v, j, t, false));
                maxv = max(maxv, maxValue(v, j + 1, t, false));
                swap(v[i][j], v[i][j + 1]);
            }
            if (i < t - 1 && c != v[i + 1][j])
            {
                swap(v[i][j], v[i + 1][j]);
                maxv = max(maxv, maxValue(v, j, t, false));
                maxv = max(maxv, maxValue(v, i, t, true));
                maxv = max(maxv, maxValue(v, i + 1, t, true));
                swap(v[i][j], v[i + 1][j]);
            }
        }
    }
    cout << maxv;
}

/*
    끔찍한 브루트포스 문제였다
    설마설마 했는데 진짜 모든 경우의 수를 다 둘러봐야 하는 문제였을 줄은...

    문자간 스왑을 하기 전 따져봐야 할 조건문은 다음과 같다.
    1. 다음 행이 현재 위치와 다른 문자인지 
    2. 다음 열이 현재 위치와 다른 문자인지

    스왑을 한 후, 따져봐야 할 최댓값 경우의 수는 다음과 같다.
    1. 위치를 바꾼 방식이 두 열의 문자를 바꾼 경우
        -> 그 행의 연속 문자의 최댓값 구하기
        -> 현재 열의 연속 문자의 최댓값 구하기
        -> 바꾼 열의 연속 문자의 최댓값 구하기
    
    2. 위치를 바꾼 방식이 두 행의 문자를 바꾼 경우
        -> 그 열의 연속 문자의 최댓값 구하기
        -> 현재 행의 연속 문자의 최댓값 구하기
        -> 바꾼 행의 연속 문자의 최댓값 구하기

    3. 그냥 안 바꾼 상태에서의 현재 행/열의 연속 문자의 최댓값 구하기

    이 문제는 진짜 있는 그대로 메서드를 안쓰고 풀면 어마어마한 코드 재사용 때문에 머리가 복잡해지기 때문에
    어떻게든 메서드화를 시키는 게 좋다.
    그리고 swap같은 기능을 C++에선 swap(a,b)으로 제공해주고 max로직도 max(a,b)형태로 제공이 되니
    구태여 swap기능을 코드로 짜거나 max로직을 짜면서 코드양 부풀리지 말고 적극적으로 활용하자..

    유일하게 행 또는 열의 연속 문자를 둘러보는 기능은 여러번 사용되지만 메서드로 제공은 안되므로 본인이 직접 작성해야한다...

    브루트 포스 문제 자체가 경우의 수를 잘 따지는 지, 배열을 둘러보기 위한 인덱스의 변화를 잘 통제하는 지를 평가하는 거여서
    코드가 다른 문제에 비해 길어질 수 밖에 없는데
    공통적으로 사용될 부분을 빠르게 잘 쳐내서 메서드화 시키려고 노력도 하고 기본 함수도 적극적으로 활용해서 코드 양을 줄이자...
    진짜 안그러면 풀어낸다 해도 면접에서 코드리뷰 시키면 코드 왜이렇게 더럽냐고 물어볼수도 있음...
*/