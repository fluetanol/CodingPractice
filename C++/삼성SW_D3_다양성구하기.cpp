// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d3다양성측정
// 24/04/24
// 10분

#include <iostream>
#include <unordered_set>
using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        unordered_set<char> us;
        string s;
        cin >> s;
        for (auto i : s)
        {
            if (us.find(i) == us.end())
                us.insert(i);
        }
        cout << "#" << test_case << " " << us.size() << endl;
    }
    return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}

//그냥 해쉬셋, 해쉬맵 쓰는 방법 물어보는 문제
//c++은 일반 set의 경우 heap정렬을 하고, unordered_set을 하면 정렬은 안하고 막무가내로 값을 넣어둔다
//필요에 따라 set을 쓰면 됨.

//알아두면 좋을 set 함수를 이 참에 알아보자

/*
    .find(요소) -> 해당 요소가 있는지 찾고 있으면 해당 이터레이터를 반환한다. 없으면 .end()반환함
    .insert(요소) ->  해당 요소를 넣는다.
    .size() -> 해당 셋의 요소 갯수를 구해준다.

    간단한 문제면 이 정도면 될 듯? 다른 걸 쓸일이 생기면 그때 또 정리해둠.
*/