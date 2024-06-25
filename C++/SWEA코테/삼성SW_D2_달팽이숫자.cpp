// https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2달팽이숫자
// 24/05/05
// 1시간...!


#include <iostream>
#include <vector>
    using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n;
        cin >> n;
        vector<vector<int>> v(n);
        for (int i = 0; i < n; i++)
        {
            vector<int> vv(n);
            v[i] = vv;
        }

        int count = 1;
        int x = 0, y = 0;
        int flag = 0;
        while (count != n * n + 1)
        {
            v[x][y] = count;

            if (flag == 0 && (x + 1 == n || v[x + 1][y] != 0))
                flag++;
            else if (flag == 1 && (y + 1 == n || v[x][y + 1] != 0))
                flag++;
            else if (flag == 2 && (x - 1 == -1 || v[x - 1][y] != 0))
                flag++;
            else if (flag == 3 && (y - 1 == -1 || v[x][y - 1] != 0))
                flag++;

            flag %= 4;
            if (flag == 0)
                x++;
            else if (flag == 1)
                y++;
            else if (flag == 2)
                x--;
            else if (flag == 3)
                y--;

            count++;
        }

        cout << "#" << test_case << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << v[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//이런 출력 형식 문제의 꿀팁을 알려주겠다
//짱구 굴리지말고
//그냥 직관적으로 조건문으로 표현할 부분 전부 표현 한 후
//추후에 조건문 코드를 최적화 하는 게 낫다
//중첩 조건문은 가독성을 위해 최대한 배제할 것.
//위 문제의 경우에도 언제 방향전환을 해야할지
//그냥 그 조건만 명확하게 수식으로 표현해주면 된다.
//나는 혹시나 더 수학적인 수려한 방법이 없나 하면서 짱구굴리다가 시간 날렸다
