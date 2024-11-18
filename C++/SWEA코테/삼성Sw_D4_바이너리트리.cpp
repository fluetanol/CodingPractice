// SWEA 바이너리트리
// D4
// 40분
// 이진 트리, 수학

#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int n, v;
        cin >> n >> v;

        int vdistance = log2(v);
        int depth = log2(n);
        int rest = n - (pow(2, depth) - 1);
        int fullleafcount = pow(2, depth);

        int maxdistance;
        if (n == 1)
            maxdistance = 0;
        else if (v == 1)
            maxdistance = depth;
        else
        {

            bool isLeft = true;
            while (true)
            {
                if (v == 2)
                {
                    break;
                }
                else if (v == 3)
                {
                    isLeft = false;
                    break;
                }
                v /= 2;
            }

            if (isLeft && rest <= fullleafcount / 2)
                maxdistance = vdistance + depth - 1;
            else
                maxdistance = vdistance + depth;
        }
        cout << "#" << test_case << " " << maxdistance << "\n";
    }
    return 0;
}