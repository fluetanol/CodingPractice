#include <iostream>
using namespace std;

int calculate(int*& arr, int n, int limit) {
    
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i] < limit ? arr[i] : limit;
    }
    return sum;
}



int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int* arr = new int[n];
    
    int left = 0;
    int right = -1;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        right = right > arr[i] ? right : arr[i];
    }
    int totallimit;
    cin >> totallimit;

   
    //left가 right를 확실히 추월하는 상황을 만들기 위해 <= 로 하는 것
    while (left <= right) {
        int mid = (left + right) / 2;
        int cost = calculate(arr, n, mid);

        if (cost == totallimit) {
            break;
        }
        else if (cost > totallimit) {
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }

    }

    cout << (left + right) / 2;

    delete[] arr;

}



/*
    이분 탐색으로 풀면 됨
    가능한 예산을 범위를 좁혀가며 풀면 된다는 느낌
    아무튼 정렬된 원소들 안에서 탐색을 하면서 풀어야 겠다 싶으면 이분탐색 의심하면 됨

    참고로 left <= right해야 left ==right인 케이스도 검증을 해볼 수 있다.
*/