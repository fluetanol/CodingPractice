// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2두개의숫자열
// 24/04/23
// 15분

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int MaxSum(vector<int> info, vector<int> arr1, vector<int> arr2, int a, int b)
{
    int max = -1;
    for (int i = 0; i < info[a] - info[b] + 1; i++)
    {
        int sum = 0;
        for (int j = i; j < i + info[b]; j++) sum += arr1[j - i] * arr2[j];
        if (max < sum)  max = sum;
    }
    return max;
}

int main(int argc, char **argv)
{
    int test_case;
    int T;

    cin >> T;
    cin.ignore();
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s1, s2, s3;
        getline(cin, s1);
        getline(cin, s2);
        getline(cin, s3);
        istringstream iss1(s1);
        istringstream iss2(s2);
        istringstream iss3(s3);
        vector<int> info;
        vector<int> arr1;
        vector<int> arr2;
        int a;
        while (iss1 >> a)
            info.push_back(a);
        while (iss2 >> a)
            arr1.push_back(a);
        while (iss3 >> a)
            arr2.push_back(a);
        int max = -1;
        if (info[0] <= info[1])
            max = MaxSum(info, arr1, arr2, 1, 0);
        else
            max = MaxSum(info, arr2, arr1, 0, 1);
        cout << "#" << test_case << " " << max << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//인덱스 조절에 목숨걸면 되는 완전탐색 문제
//정렬이 가능했으면 모르겠는데 배열을 그대로 둔 상태로 탐색해야해서
//그냥 무식하게 인덱스 값 조절하며 완전 탐색해보는게 가장 편하다.
//주어진 입력값 케이스도 그리 크지 않아서 괜찮음.
//그보다 입력 데이터 처리하는 게 더 까다로움