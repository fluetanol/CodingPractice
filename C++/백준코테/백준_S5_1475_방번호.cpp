#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    string n;
    cin >> n;
    int nums[10] = {};

    for (int i = 0; i < n.size(); ++i)
    {
        int real_num = n[i] - '0';
        nums[real_num]++;
    }

    int max = -1;
    for (int i = 0; i < 10; ++i)
    {
        if (max < nums[i] && i != 6 && i != 9)
        {
            max = nums[i];
        }
    }

    int avg = ceil(float(nums[6] + nums[9]) / 2);
    max = max > avg ? max : avg;
    cout << max;
}


//예외 케이스 :  6과 9의 개수가 홀수인 경우
//어차피 6과 9는 서로 공유가 되므로, 둘을 평균낸 뒤의 반올림 값을 받아오면 된다 (여기선 어차피 가능한 가짓수가 0.5인 경우뿐이므로 ceil씀)

// 주의 사항
// nums는 int 형인데 이를 2로 나누면 소수점은 버림처리되기 때문에 ceil이 의도한대로 동작이 안된다
// float 형 변환 -> 정확한 값 도출 -> ceil 처리 -> int 형 변환 순서로 진행하는 것을 잊지말자
//이런 식의 숫자 형변환을 통한 올림, 반올림, 내림 연산이 꽤 빈번하게 나옴