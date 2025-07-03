#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int tet[3][4][2] = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
    {{0, 0}, {0, 1}, {0, 2}, {0, 3}},
    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
};

// x축 대칭 기준점 : 1.5
// y축 대칭 기준점 : 0.5

int mask[3][2][2] = {
    {{0, 0}, {0, 2}},
    {{0, 0}, {0, 1}},
    {{0, 0}, {1, 2}},
};

// 대칭 순서
int symmetery[4]{
    1, 2, 1, 2};

bool isRange(int x, int y, int n, int m)
{
    return (x >= 0 && x < n) && (y >= 0 && y < m);
}

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    int **arr = new int *[n];
    for (int i = 0; i < n; ++i)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; ++j)
        {
            cin >> arr[i][j];
        }
    }

    int maxv = -1;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int sum = 0;

            // cout << " current : " << j << " " << i << endl;

            // 기본 케이스 ㅁ, ㅣ, ㅡ에 대한 최대값
            for (int k = 0; k < 3; ++k)
            {
                for (int l = 0; l < 4; ++l)
                {
                    int dx = i + tet[k][l][0];
                    int dy = j + tet[k][l][1];

                    if (isRange(dx, dy, n, m))
                    {
                        sum += arr[dx][dy];
                    }
                    else
                    {
                        sum = 0;
                        break;
                    }
                }
                maxv = max(maxv, sum);
                sum = 0;
            }

            // i, j에서의 6칸 합
            sum = 0;
            bool canSum = true;
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    int dy = i + k;
                    int dx = j + l;

                    if (isRange(dy, dx, n, m))
                    {
                        sum += arr[dy][dx];
                    }
                    else
                    {
                        sum = 0;
                        canSum = false;
                        break;
                    }
                }
                if (!canSum)
                    break;
            }
            // cout << sum << endl;
            if (canSum)
            {
                // cout << i << " " << j << " " << sum << endl;
                // i,j 에서 가능한 모든 mask 빼기
                for (int k = 0; k < 3; k++)
                {
                    int cacheSum = sum;

                    // 해당 마스크 계산할 떄 마다 대칭시키기
                    for (int m = 0; m < 4; m++)
                    {

                        for (int l = 0; l < 2; l++)
                        {
                            // cout << "("<< mask[k][l][0] << ", "  << mask[k][l][1] << ") " ;
                            int dy = i + mask[k][l][1];
                            int dx = j + mask[k][l][0];
                            cacheSum -= arr[dy][dx];

                            int flag = symmetery[m];

                            // y축 대칭
                            if (flag == 1)
                            {
                                mask[k][l][0] = flag - mask[k][l][0];
                            }
                            // x축 대칭
                            else
                            {
                                mask[k][l][1] = flag - mask[k][l][1];
                            }
                        }

                        // cout << "result : " << cacheSum << " \n";
                        // 해당 케이스 다 뻈으면 다시 원점 복구
                        maxv = max(maxv, cacheSum);
                        cacheSum = sum;
                    }
                }
            }

            // cout << "-----**************-----" << endl;

            // i, j에서의 6칸 합
            sum = 0;
            canSum = true;
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    int dy = i + k;
                    int dx = j + l;

                    if (isRange(dy, dx, n, m))
                    {
                        sum += arr[dy][dx];
                    }
                    else
                    {
                        sum = 0;
                        canSum = false;
                        break;
                    }
                }
                if (!canSum)
                    break;
            }

            if (canSum)
            {
                // cout << i << " " << j << " " << sum << endl;

                // i,j 에서 가능한 모든 mask 빼기
                for (int k = 0; k < 3; k++)
                {
                    int cacheSum = sum;

                    // 해당 마스크 계산할 떄 마다 대칭시키기
                    for (int m = 0; m < 4; m++)
                    {
                        for (int l = 0; l < 2; l++)
                        {
                            // cout << "(" << mask[k][l][1] << ", " << mask[k][l][0] << ") ";
                            int dy = i + mask[k][l][0];
                            int dx = j + mask[k][l][1];
                            cacheSum -= arr[dy][dx];

                            int flag = symmetery[m];

                            // y축 대칭
                            if (flag == 2)
                            {
                                mask[k][l][1] = flag - mask[k][l][1];
                            }
                            // x축 대칭
                            else
                            {
                                mask[k][l][0] = flag - mask[k][l][0];
                            }
                        }

                        //	cout << "result : " << cacheSum << " \n";
                        // 해당 케이스 다 뻈으면 다시 원점 복구
                        maxv = max(maxv, cacheSum);
                        cacheSum = sum;
                    }
                }
            }
        }
    }

    cout << maxv << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}


/*
    풀이법

    그냥 노가다 했다.
    가능한 테트로미노의 회전, 대칭 경우를 모두 고려해서 전부 찍어내고 그 중 최대값 찍었다.
    에휴
*/