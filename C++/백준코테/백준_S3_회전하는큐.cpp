#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);

    for (int i = 0; i < n; ++i) v[i] = i + 1;

    int count = 0;

    //front pointer
    int pivot = 0;

    for (int i=0; i<m; ++i)
    {
        int k;
        cin >> k;

        //size 1 -> no moving
        if (v.size() == 1) break;

        //right direction count
        int right = 0;
        //left direction count
        int left = 0;

        // right count
        int idx = pivot;
        while (true)
        {
            if (v[idx] == k) break;
            idx = (idx + 1) % v.size(); //idx out of range protect
            right++;
        }

        //left count
        idx = pivot;
        while (true)
        {
            if (v[idx] == k) break;
            idx = ((idx - 1 + v.size()) % v.size()); // idx out of range protect
            left++;
        }

        count += right < left ? right : left;   //greedy sum (least number sum)

        v.erase((v.begin() + idx));

        pivot = idx % v.size();     // idx out of range protect (because of erasing operation)
    }
    cout << count;
}


//의외로 그리디 알고리즘 문제

// 좌, 우 움직임 카운트에 별 다른 추가 제한사항이나 조건이 없고 무조건 "정해진 순서"로 배열을 삭제하기 때문에
// 그때 그때마다 가장 빠른 길을 고르면 되는 문제다.
// 예전에 프로그래머스 문제 중에선 커서를 움직여서 문자열을 바꿀 때 가장 최소로 움직이는 법을 구하는 문제가 있었는데
// 그 문제는 문자열을 바꾸는 순서에 제한을 두지 않았기 때문에 당장 더 짧은 길을 택하더라도 틀릴 수도 있었다. 
// 즉, 그리디 알고리즘인척 하는 브루트 포스 문제였음


//한편 자료구조 측면에서 보면 데큐 문제이기도 한데
//데큐란 큐의 확장판으로, 앞 뒤 모두에 삭제와 삽입이 가능한 자료구조다.

//위 문제는 좌로 이동시 맨 앞의 원소가 뒤에 삽입이 되고, 우로 이동 시 맨 뒤의 원소가 앞으로 삽입이 된다.
//즉, 이상적인 풀이는 데큐 이용해서 앞뒤로 원소 삽입해서 이동시키며 풀라는 문제가 맞다.

// 다만 나는 그 삭제 삽입 과정에서 물리적인 오버헤드가 있을거라 생각해서
// 그냥 일반적인 리스트 구조에서 pivot포인터로 front가 어디인지 인덱스를 옮겨가면서 erase하는 방식을 택했다.
// 덕분에 인덱스 연산을 갱신하면서 (% v.size()부분) exception문제 위험을 감수해야하긴 했지만
// 그래도 진짜 데큐로 푸는 것과 큰 난이도 차이는 없는듯

// 자세한 풀이는 주석 참고