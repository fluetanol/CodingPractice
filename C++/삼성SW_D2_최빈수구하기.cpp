// https : // swexpertacademy.com/main/solvingProblem/solvingProblem.do
// 삼성아카데미d2최빈수구하기
// 24/05/10
// 5분

#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        int n;
        vector<int> v(101);
		cin >>n;
        for(int i=0; i<1000; i++){
            int k;
            cin >> k;
            v[k]++;
        }
        
        int max = -1;
        int idx = -1;
        for(int i=0; i<100; i++){
            if(max <= v[i]) {
             	max = v[i];
                idx = i;
            }
        }
        	cout << "#" << test_case << " " <<idx <<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

//필요한 메모이제이션 공간이 100개밖에 안되니 
//hashmap 말고 위와같이 푸는게 성능적으로 더 효율적인 문제