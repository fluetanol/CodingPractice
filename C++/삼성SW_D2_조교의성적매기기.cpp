// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2조교의성적매기기
// 24/04/27
// 30분

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    string grades[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, k;
        cin >> n >> k;
        vector<float> v;
        int kidx = -1;
        for (int i = 1; i < n + 1; i++)
        {
            float a, b, c;
            cin >> a >> b >> c;
            float score = a * 0.35f + b * 0.45f + c * 0.2f;

            if (v.size() == 0)
                v.push_back(score);
            else
            {
                bool isInsert = false;
                for (int j = 0; j < v.size(); j++)
                {
                    if (v[j] > score)
                    {
                        isInsert = true;
                        v.insert(v.begin() + j, score);
                        if (kidx == -1 && i == k)
                            kidx = j;
                        else if (kidx != -1 && j <= kidx)
                            kidx++;
                        break;
                    }
                }
                if (!isInsert)
                {
                    v.push_back(score);
                    if (kidx == -1 && i == k)
                        kidx = v.size() - 1;
                }
            }
        }
        int divide = n / 10;
        int grade = (n - 1 - kidx) / divide;
        cout << "#" << test_case << " " << grades[grade] << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//d2에 이상하고 성가신 문제가 많다..

// 푸는 원리 k번째로 입력받은 학생의 정렬 인덱스를 계속 추적하는 방식을 썼다.
// input이 들어올때마다 바로 정렬을 하는 삽입정렬 방식을 썼는데,
// 이때 k번째 학생의 성적이 정렬된 순간의 인덱스를 저장한 후 ( if (kidx == -1 && i == k)kidx = j;)
// 만약 그 뒤에 정렬되는 학생들의 성적이 k번째 학생의 현재 인덱스보다 작다면
// 그 뒤에 있는 정렬 멤버들이 한칸씩 뒤로 밀리므로 k번째 학생의 인덱스 또한 1 더해서 저장해준다
//      else if (kidx != -1 && j <= kidx) kidx++;

//이런 식으로 최종적인 k번째 학생의 정렬 인덱스를 이용해서 grade 구간을 구해준다
//위 방식은 아쉽게도 오름차순 방식이라 n에서 kidx를 빼서 인덱스를 내림차순 한 것처럼
//역전 시켜서 grade구간을 구해야 하는 번거로움이 있긴 하다.

//최종적으로 미리 저장해둔 grades 성적 문자열 배열에서 성적 문자를 빼와서 그걸 출력시켜주면 된다

// string grades[10] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
//...
//        int divide = n / 10;
//        int grade = (n - 1 - kidx) / divide;
//         cout << "#" << test_case << " " << grades[grade] << endl;

//대단한 알고리즘을 물어보는 문제들은 d2에 그리 많진 않은데
//성가신 구현문제가 많이 깔려있다...
//문제다운 문제는 d3~d4구간 부터 시작되는듯