// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2중간평균값구하기
// 24/04/24
// 15분

#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    cin.ignore();
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string s;
        vector<int> v;
        getline(cin, s);
        istringstream iss(s);
        int n;
        int max = -1;
        int min = 99999;
        while (iss >> n)
        {
            v.push_back(n);
            if (max < n)
                max = n;
            if (min > n)
                min = n;
        }

        float sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (v[i] != max && v[i] != min)
            {
                sum += v[i];
            }
        }
        sum = round(sum / 8);
        cout << "#" << test_case << " " << sum << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//딱히 설명할게 없는 구현문제라 넘어감