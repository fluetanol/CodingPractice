#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    bool paper[100][100]={};
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;

        for (int j = x; j < x + 10; ++j)
        {
            for (int k = y; k < y + 10; ++k)
            {
                paper[j][k] = true;
            }
        }
    }

    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if (paper[i][j] == true)
            {
                count++;
            }
        }
    }

    cout << count;
}


//내가 놓친 부분 : bool 배열의 초기화
//해결 : 처음엔 그냥 반복문으로 초기화 했음

//추가 설명 :
//C++에서는 전역변수로 선언된 배열은 자동으로 0으로 초기화 되지만
//지역변수로 선언된 배열은 초기화가 되지 않음
//따라서 지역변수로 선언된 bool 배열은 쓰레기 값이 들어가 있을 수 있음, 이거 때문에 count 를 셀 때 쓰레기값을 true로 인식한 문제가 있었는듯
    
//참고로 c++11 이상에서는 std::array 나 std::vector 를 사용하여 배열을 초기화할 수 있는데, 이렇게 초기화 하는 경우
//모든 원소가 0 또는 false로 초기화 됨
//이 문제에서는 false로 초기화 해야 했기 때문에 반복문으로 초기화 함

//더 나은 방법
//배열 초기화 할 때
//bool paper[100][100] = {};
//이렇게 하면 모든 원소가 false로 초기화 됨