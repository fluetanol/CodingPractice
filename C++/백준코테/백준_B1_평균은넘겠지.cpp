// 문제번호 : 4344번
// 평균은 넘겠지
// 푼 시간 : 15분
// 알고리즘 분류 : 수학

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        float avg = 0;
        int *scoreArray = new int[k];

        for (int j = 0; j < k; j++)
        {
            int score;
            cin >> score;
            avg += score;
            scoreArray[j] = score;
        }

        avg /= k;
        float count = 0;
        for (int j = 0; j < k; j++)
        {
            if (avg < *(scoreArray + j))
            {
                count++;
            }
        }

        float rate = (count / k) * 100;
        cout << rate << "%\n";
        delete[] scoreArray;
    }
}
