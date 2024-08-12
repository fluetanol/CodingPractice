// 문제번호 : 1039번
// 교환
// 푼 시간 : 3시간
// 알고리즘 분류 : 그래프 탐색, 너비 우선 탐색, (정렬)

#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

// 현재 정렬해야 위치에 들어 올 수 있는 최댓 값
int getMax(string &s, int i)
{
    int max = -1;
    for (int j = i; j < s.size(); j++)
        if (max < s[j] - '0')
            max = s[j] - '0';
    return max;
}

// 같은 한 쌍의 수가 존재하는지만 파악하는 함수
void getSameidx(string &s, int &idx1, int &idx2)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                idx1 = i;
                idx2 = j;
                break;
            }
        }
    }
}

void Swapping(string s, int k, int i, int count, vector<int> &v)
{

    if (count == k)
        return;

    // k까지 count하기도 전에 정렬이 끝난 경우 (최댓값 등장)
    else if (i == s.size())
    {
        int idx1 = -1, idx2 = -1;
        getSameidx(s, idx1, idx2);

        // 1. 단 한쌍의 같은 수만 있다면 그 두개의 수를 돌려서 최댓값을 유지함
        if (idx1 > -1)
            v[v.size() - 1] = stoi(s);
        else
        {
            // 2. 그런 수가 없다면 가장 낮은 두 자리 수만 바꿔서 격차를 최소화함
            for (int i = count; i < k; i++)
            {
                swap(s[s.size() - 1], s[s.size() - 2]);
                v[i] = stoi(s);
                if (s[0] == '0')
                {
                    v[v.size() - 1] = -1;
                    break;
                }
            }
        }
        return;
    }

    int max = getMax(s, i);
    bool isChange = false;
    for (int j = i; j < s.size(); j++)
    {
        if (s[j] - '0' == max && s[i] != s[j] && i != j)
        {
            string temp = s;
            isChange = true;
            swap(temp[i], temp[j]);

            int tempi = stoi(temp);
            if (v[count] < tempi)
            {
                v[count] = stoi(temp);
                Swapping(temp, k, i + 1, count + 1, v);
            }
        }
    }

    // 해당 위치 i에 다른 값이 올 필요가 없는데
    // 아직 k번의 자리바꿈이 끝나지 않은 경우
    if (count < k && !isChange)
        Swapping(s, k, i + 1, count, v);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    int k;
    cin >> n >> k;

    if (n.size() == 1)
    {
        cout << -1;
        return 0;
    }

    vector<int> v(k);
    Swapping(n, k, 0, 0, v);

    cout << v[k - 1] << endl;
}


//보통은 dfs, bfs같은 탐색 알고리즘으로 풀면 된다. 자릿수가 7개가 끝이라서 들어갈 depth도 적음
//그래서 보통의 다른 풀이들(아래에 적어 놓겠음)은 4ms~8ms정도 걸린다

//하지만 위 방법은 꽤 무식하게 패턴을 파악해서 푼 방법으로
//오히려 selection sorting방식의 정렬의 특성을 이용한 알고리즘이라고 봐야 한다.

//알고리즘은 다음과 같은 규칙성을 파악하여 세웠다

/*
     1. selection sorting으로 정렬할 때는 보통 어떤 idx에 올 수 있는 가장 큰 수를 찾는 방식을 쓴다.
     ex) 12345인 경우, 첫번째 위치엔 5가 오면, 두번째 위치는 그 다음으로 큰 수 4가 오게 됨

     2. k번 자리 바꿈을 할 때 
        1) k번의 swap연산 이내에 최댓값에 도달하지 못한 경우 
            -> 그냥 현재까지 1번의 규칙을 바탕으로 swap한 최근 결과를 반환한다.
        2) k번에 도달하기 한참 전에 이미 최댓값이 도달하여 k번이 남은 경우
            -> 적절히 현재 구한 최댓값의 변량을 최소화 시킬 방법을 찾는다.
    
    3. 앞 자리에 0이 오는 경우 -> 문제 규칙상 불가능 판정으로 바로 -1을 출력

    4. 주어진 숫자 자리수 자체가 1의 자리수인 경우 -> swap자체가 불가능하므로 -1을 출력
*/


//여기까진 꽤 쉽게 파악 가능한 규칙인데
//이 안에서 발견하기 어려운 특수한 고려사항이 있다.

/*
    1. selection sorting을 이용하는 방법은 보통 서로 다른 원소를 정렬할 때에나 swap시 그다음 가장 큰 수를 반환시켜준다.
    -> 이 뜻은 최댓값이 같은 숫자가 여러개가 있다면 다음 큰 숫자가 그 여러개 중 어떤게 될지는 모른다는 것.
    -> 즉 모르기 때문에 여기에선 dfs를 써서 더 큰 방향의 숫자가 뭔지 전부 뒤져봐야함

    ex) 123666의 경우, 1이 4번째자리의 6이랑 바꿀지, 5번째 자리의 6과 바꿀지, 6번째 자리의 6과 바꿀지
    뭐를 바꾸느냐에 따라 수의 대소가 달라지기 때문에
    623661. 623616, 623166 이렇게 세가지 경우를 모두 뒤져봐야함
    이 케이스에선 623661이 가장 큼

    2. k번 자리 바꿈을 하기 전에 최댓값에 도달한 경우
    -> 만약 단 한쌍의 같은 수가 존재한다면 그냥 그 둘을 무한히 바꿔서 최댓값의 현상 유지를 시도한다.
    -> 근데 그런게 없다면 최댓값으로 부터 멀어지는 걸 최소화 하기 위해 십의 자리수와 일의 자리수를 교환해야 한다 (k번 자리 바꿈이 될 때 까지!)


    3. selection sorting중 어떤 idx의 수가 이미 최댓 값인 경우
    -> swap을 할 이유가 없으므로 count를 증가시켜선 안된다. swap을 안한 상태로 다음 idx로 넘어감
*/

/*
    여기까지의 규칙성을 파악하고 나면 
    
    결국은 1번의 상황 때문에 dfs를 이용해 풀어야 함을 알 수 있긴 하지만 

    단순히 모든 경우의 swap 가능성을 뒤져보는 것 보다야 엄청나게 제약을 걸어 놓은 상황이기 때문에

    실제 시간 성능은 아주 빠르다. (0ms였음)

    다만 이건 특수한 경우고 착한 어린이는 러프한 dfs를 쓰도록 하자.

    input 제한 범위부터가 러프하게 풀어도 됨을 암시하고 있었음.
*/


//다르게 풀어본 풀이

using namespace std;

void swapping(string s, int k, int count, vector<int> &v)
{
    if (k == count)
        return;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            string temp = s;
            swap(temp[i], temp[j]);

            if (v[count] < stoi(temp) && temp[0] != '0')
            {
                v[count] = stoi(temp);
                swapping(temp, k, count + 1, v);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;
    int k;
    cin >> n >> k;

    if (n.size() == 1)
    {
        cout << -1;
        return 0;
    }

    vector<int> v(k);
    for (int i = 0; i < v.size(); i++)
        v[i] = -1;
    swapping(n, k, 0, v);
    cout << v[k - 1];
}


//아니 이상하네

//똑같은 dfs인데

//다른 애들은 4ms~8ms 걸리는데

//이건 0ms가 터졌다

//왜그런건진 모르겠음

//뭐야 걍 이렇게 풀어도 된거잖아 개꿀