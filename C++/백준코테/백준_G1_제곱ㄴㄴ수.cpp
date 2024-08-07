// 문제번호 : 1016번
// 제곱 ㄴㄴ수
// 푼 시간 : 2시간
// 알고리즘 분류 : 수학, 에라토스테네스의 체

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_set>

using namespace std;

int main()
{
    long long count = 0;
    long long min, max;
    cin >> min >> max;

    unordered_set<long long> us;

    if (max < 3)
    {
        cout << (max - min) + 1;
        return 0;
    }

    int idx = 2;

    while (idx <= (long long)sqrt(max))
    {
        long long doubleNum = (idx * idx);
        //배수 곱의 시작점
        long long multipleStart = min % doubleNum == 0
                                      ? min / doubleNum
                                      : (min / doubleNum) + 1;
        // 짝수 제곱들은 전부 4의 배수입니다. 즉 k^2에서 k=2일때를 제외하곤 체크할 이유가 없음
        if (idx % 2 == 0 && idx > 2)
        {
            idx++;
            continue;
        }

        // 제곱수의 배수인지를 체크
        while (true)
        {
            long long val = doubleNum * multipleStart;

            // max를 넘어가면 브레이크
            if (val > max) break;

            // 한번도 못찾은 원소인 경우 count
            if (us.find(val) == us.end())
            {
                us.insert(val);
                count++;
            }

            multipleStart++;
        }
        idx++;
    }

    cout << (max - min) + 1 - count;
}


//에라토스테네스의 체의 아이디어를 차용하는 문제인데
//min~max까지 그 아래의 모든 제곱수들 중 약수가 단 하나도 없는 수를 찾는게 아니라
//반대로 제곱수의 배수는 제곱ㄴㄴ수가 아니임을 역으로 이용하는 방법이다.

//방법은 이렇다

/*
    1. i = 2부터 (1보다 큰 제곱수이므로) 그 제곱수를 구한다.

    2. 배수를 할 시작점을 구하는데, 이는 min값에 따라 달려있다.
    가령 min이 16이라면 i=2의 제곱수 4는 *4부터 곱하기를 시작해야 한다.
    쉽게 min/(i^2) 으로 구하면 됨.

    3. 그 제곱수의 배수를 구하는데, 배수는 max보다 같거나 작을 때까지 구한다.

    4. 그 배수가 처음 나온 경우엔 count를 해준다. 
    이를 set에 넣어서 나중에 또 다시 같은 값이 나올때의 중복 count를 방지하자.

    5. 이렇게 구한 count를 전체 범위의 수에서 빼주면 된다. 
    count는 제곱수를 카운트한거지 제곱 ㄴㄴ수를 카운트 한게 아니임.
*/


/*
    아이디어 자체는 1시간정도 고민하면 쉽게 나오지만 세세한 구현에 따라서 성능이 갈리는데
    
    나같은 경우는 set를 써서 그런지 내부 해쉬 함수 연산으로 인한 오버헤드와
    
    너무 무겁고(long long) 많은 데이터로 인한 bucket overflow가 자주 있었는지

    실제 소모된 시간은 최소 56ms, 최대 64ms까지 찍었다.

    사실 이 문제는 set를 쓰지 않고 벡터만으로 풀수도 있는데 아래가 그 예시다.

*/


long long number[1000001];

int main(void)
{
    long long min, max;
    int cnt = 0;

    scanf("%lld %lld", &min, &max);

    for (long long i = 2; i * i <= max; i++)
    {
        long long n = min / (i * i);

        if (min % (i * i))
            n++;

        while (n * i * i <= max)
        { // n*i*i는 min보다 크거나 같은 i의 제곱수의 배수
            number[n * i * i - min] = 1;
            n++;
        }
    }

    for (int i = 0; i <= max - min; i++)
    {
        if (number[i] == 0)
            cnt++;
    }

    printf("%d", cnt);
    return 0;
}


//벡터를 쓴 버전인데
//어차피 주어진 인풋의 범위는 10000이다.
//인덱스에 따른 구간만 변경해주며 되는데,

//가령 min = 100, max = 1500이라면, 이제부터 0번지는 min, 1400번지가 max가 된다.

//즉, 어떤 제곱수의 배수 k가 min보다 같거나 크고 max보다 같거나 작은 수라면

//number[k-min] = 1로 표시해두고, 마지막엔 0인 값들만 카운트하면 된다.

//나는 이 방법을 그대로 응용해서 내 코드에 적용시켜봤는데

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    long long count = 0;
    long long min, max;
    cin >> min >> max;
    vector<bool> v(1000001);

    long long idx = 2;

    while (idx <= (long long)sqrt(max))
    {
        if (max < 3)
            break;
        long long doubleNum = idx * idx;
        // 배수 곱의 시작점
        long long multipleStart = min % doubleNum == 0
                                      ? min / doubleNum
                                      : (min / doubleNum) + 1;

        // 짝수 제곱들은 전부 4의 배수입니다. 즉 k^2에서 k=2일때를 제외하곤 체크할 이유가 없음
        if (idx % 2 == 0 && idx > 2)
        {
            idx++;
            continue;
        }

        // 제곱수의 배수인지를 체크
        while (true)
        {
            long long val = doubleNum * multipleStart;

            // max를 넘어가면 브레이크
            if (val > max)
                break;

            // 한번도 못찾은 원소인 경우 count
            if (v[val - min] == 0)
            {
                v[val - min] = 1;
                count++;
            }

            multipleStart++;
        }
        idx++;
    }

    cout << (max - min) + 1 - count;
}

//이런 느낌이다. 
// 딱 바뀐건 set에서 벡터로 바뀌었다는 것
// 있는지 없는지만 체크하면 되서 벡터 타입은 bool로
// 마지막으로 val중복 count를 막기 위한 코드만 
// 위 아이디어대로 v[val-min] = 1로 체크해주었다.



//성능평가를 해보니 대성공이였는데
//무려 12ms로 줄어들 뿐만 아니라, 기존 25000KB정도의 메모리에서 2164KB로 다이어트에 성공했다.
//확실히 set쓰는 건 조심해야 할듯.