#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

//10798 세로읽기
int main(int argc, char** argv)
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);

	
	char arr[15][15];
	for (int i = 0; i < 15; ++i) {
		for (int j = 0; j < 15; ++j) {
			arr[i][j] = '@';
		}
	}


	stringstream ss;
	int len = 0;
	for (int i = 0; i < 5; ++i) {
		string s;
		cin >> s;
		if (len < s.size()) len = s.size();

		for (int j = 0; j < s.size(); ++j) {
			arr[i][j] = s[j];
		}
	}


	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (arr[j][i] != '@') {
				ss << arr[j][i];
			}
			else {
				continue;
			}
		}
	}

	cout << ss.str();



}

//못 잡은 케이스 : 처음과 끝 부분이 중간 보다 짧은 경우
//해결 : 전체에서 가장 긴 문자열 길이를 캐싱했다.

//그외 특이사항
//공백의 자리는 '@'로 채워넣음, 애초에 문제 조건상 그런게 나올리가 없기 떄문임
//하지만 만약 모든 문자가 다 가능하다면 ' ' 로 채워넣을거 같습니다.