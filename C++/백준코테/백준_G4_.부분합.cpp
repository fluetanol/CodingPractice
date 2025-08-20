
#include <iostream>

using namespace std;

int arr[100000];
int INITIAL_MAX = 999999999;

int main()
{
    cin.tie(0);
    cout.tie(0);
    
    size_t n, s;
    cin >> n >> s;

    for (int i = 0; i < n; ++i) cin >> arr[i];
    
    int start = 0;
    int sum = 0;
    int minv = INITIAL_MAX;

    //투 포인터를 flag로 컨트롤 안해도 됨
    for (int end = 0;  end < n; ++end) {
        sum += arr[end];
        
        if (sum >= s) {
            //start가 end랑 같을 때 까지 (start == end 일때, 즉 길이가 1인 경우도 따져봐야함)
            // . 또는 sum 이 s보다 같거나 큰 동안 start 옮기기
            while (start <= end && sum >= s) {
                minv = min(end - start + 1, minv);
                sum -= arr[start++];
            }
        }
    }

    if (minv == INITIAL_MAX) minv = 0;
    cout << minv;


}


// 투포인터 문제
// 그냥 투 포인터를 써서 부분합 구간 가장 짧은걸 구하면 됨
// 그런데 굳이 flag로 컨트롤 하지 말고
// right 포인터를 기본 증가 변수로 두되, 
// left 포인터를 조건을 걸어서 증가시키는 로직으로 가는게 깔끔하고 좋다.
// 기본 양식이 그런거 같음