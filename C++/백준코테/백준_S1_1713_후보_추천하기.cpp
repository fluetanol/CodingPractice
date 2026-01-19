#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
    pq 문제인데 필요한 인자가 두개임

    1. 기간
    2. 추천 수

    추천 수가 낮을 수록 빠르게 죽고,
    동일 추천 수라면 기간이 오래될 수록 빠르게 죽음

    내 계획

    1. 추천수가 이제 1로 올라간 애들(새로 들어오는 애들) 은 일단 무조건 삽입 시킴
    만약 주어진 액자 수 이상이면 앞에 것을 뺌

    2. 추천수가 이미 1이상이라면 새로운 구조체를 다시 짜서 보냄
    이때 구조체의 order는 이전 order값과 동일해야 함

    3. 앞에 것을 뺄 떄, 만약 내가 기록한 추천 수와 안쪽의 구조체 추천 수가 다르다면
    이건 거짓 정보이므로 그냥 무시하고 진짜 정보를 만날 때 까지 뺴야함.


*/

struct student
{
    int num;
    int time;
    int recommend;

    student(int num, int time, int recommend) : num(num), time(time), recommend(recommend) {}

    // 잊지 말것
    // this (자기자신)과 비교했을 때, "내가(this) 더 뒤에 와야 하는가?"
    // 에 대한 답변이 return 의 값이면 됨
    // 따라서 true면 새로 들어오는 것이 더 위로 가고, false면 더 아래로 감

    // 추천 수가 작을 수록, 그리고 동일하다면 더 오래될 수록(time 이 더 작음)
    bool operator<(const student s) const
    {
        if (this->recommend != s.recommend)
            return this->recommend > s.recommend;
        else
            return this->time > s.time;
    }
};

int main(int argc, char **argv)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    priority_queue<student> pq;
    vector<int> recommend(101);
    vector<int> order(101);

    int n, r;
    cin >> n >> r;

    int avail_size = n;
    int count = 0;
    for (int i = 1; i <= r; ++i)
    {
        int stu_num;
        cin >> stu_num;

        recommend[stu_num]++;
        if (order[stu_num] == 0)
            order[stu_num] = i;

        if (pq.size() < avail_size && recommend[stu_num] == 1)
        {
            // cout << "putin : " << stu_num << " order : " << order[stu_num] << endl;
            pq.push(student(stu_num, order[stu_num], recommend[stu_num]));
            count++;
        }
        // 이미 있던 녀석의 추천 수를 늘리는 경우
        else if (recommend[stu_num] > 1)
        {
            pq.push(student(stu_num, order[stu_num], recommend[stu_num]));
            avail_size++;
        }
        // 꽉 찬 경우
        else
        {
            while (true)
            {
                student stu = pq.top();
                int temp_stu_num = stu.num;
                int temp_stu_recom = stu.recommend;
                // cout << "pop : " <<  pq.top().num << " " << "recom : " << pq.top().recommend<< " comp :" << recommend[pq.top().num]<< endl;
                pq.pop();

                // 진짜 빼야할 정보가 나오면 거기서 중단, 그리고 뺸 정보는 초기화
                if (recommend[temp_stu_num] == temp_stu_recom)
                {
                    // cout << "중단! " << endl;
                    recommend[temp_stu_num] = 0;
                    order[temp_stu_num] = 0;
                    break;
                }
                // 만약 top의 원소를 꺼내어 봤는데, recommend 배열의 수치와 일치하지 않으면
                // 이는 갱신된 상태이기 때문에, 지금 꺼낸 정보는 중복된 거짓 정보라는 것을 의미합니다.
                else
                {
                    avail_size--;
                }
            }
            // cout << "putin : " << stu_num << endl;
            // 추천수만 변동시키라 했으므로 order는 이전 정보를 그대로 가져와야 합니다.
            pq.push(student(stu_num, order[stu_num], recommend[stu_num]));
        }

        // cout << "size :  "<< avail_size << endl;
    }

    for (int i = 0; i < recommend.size(); ++i)
    {
        if (recommend[i] > 0)
        {
            cout << i << " ";
        }
    }
}
