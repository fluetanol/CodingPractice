// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3무한사전
// 24/04/28
// 10분

#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        string p, q;
        cin >> p >> q;

        // if(p.length() < 10)
        p = p + "a";
        /*
        else{
            for(int i=9; i>=0; i--){
                if(p[i] != 'z') {
                    p[i]++;
                    break;
                }
                else  p.erase(p.end()-1);
            }
        }*/

        if (p == q)
            cout << "#" << test_case << " " << "N" << endl;
        else
            cout << "#" << test_case << " " << "Y" << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//어처구니 없게도 사전에 등록 가능한 단어의 가능한 길이가 무한대여서
//다음 단어는 무조건 a를 덧붙히면 끝나는 문제였다...
//주석처리 된 부분은 길이 제한이 10인 경우 다음 단어를 판정해주는 조건문...
//이런게 d3...?