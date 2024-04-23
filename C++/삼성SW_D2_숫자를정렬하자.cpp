// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2숫자를정렬하자
// 24/04/23
// 20분 (insertion)

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void InsertionSort(istringstream &iss, vector<int> &arr)
{
    int k;
    int idx = 0;
    while (iss >> k)
    {
        if (idx == 0)
            arr.push_back(k);
        else
        {
            int i = 0;
            for (i = 0; i < idx; i++)
            {
                if (arr[i] > k)
                {
                    arr.insert(arr.begin() + i, k);
                    break;
                }
            }
            if (i == idx)
                arr.push_back(k);
        }
        idx++;
    }
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    cin.ignore();
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string c;
        string s;
        getline(cin, c);
        getline(cin, s);
        istringstream iss(s);
        vector<int> arr;
        InsertionSort(iss, arr);

        cout << "#" << test_case << " ";
        for (int i = 0; i < stoi(c); i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

// 삽입정렬로 구현한 방식
// 입력이 들어오자마자 삽입될 위치를 선정해주는 방식의 정렬
// n의 크기가 5~50정도여서 문제 특성상 이렇게 구현 하는 게 더 효율적일수도 있다.
// 다만 n의 크기가 이를 무시할 정도로 1000~10000단위로 커지면 무조건 머지소트 쓰거나
// 내장 stl 소팅 함수 <algorithm>의 sort(start, finish, compare) 를 써주도록 한다...
// 자세한 사항은 https://blog.naver.com/ndb796/221227975229 참고