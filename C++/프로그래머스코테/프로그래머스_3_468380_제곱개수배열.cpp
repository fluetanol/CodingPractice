#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

void get_lr_pair(pair<int, int> &left, pair<int, int> &right, vector<int> &arr, long long l, long long r)
{
    long long temp_sum = 0;
    bool flag = false;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (!flag && temp_sum + arr[i] >= l)
        {
            left = {i, l - temp_sum};
            flag = true;
        }
        if (flag && temp_sum + arr[i] >= r)
        {
            right = {i, r - temp_sum};
            break;
        }
        temp_sum += arr[i];
    }
}

long long get_sum(pair<int, int> &l, pair<int, int> &r, vector<int> &arr)
{
    long long start_val = arr[l.first];
    long long end_val = arr[r.first];
    long long sum = 0;

    if (l.first == r.first)
    {
        sum = start_val * (r.second - l.second + 1);
    }
    else
    {
        sum = start_val * (start_val - l.second + 1) + end_val * r.second;

        for (int i = l.first + 1; i < r.first; ++i)
        {
            sum += (long long)arr[i] * (long long)arr[i];
        }
    }
    return sum;
}

void move_pair(pair<int, int> &p, int offset, int arrval)
{
    int idx = p.first;
    int pos = p.second;

    if (pos + offset > arrval)
    {
        p.first++;
        p.second = 1;
    }
    else
    {
        p.second = pos + offset;
    }
}

vector<long long> solution(vector<int> arr, long long l, long long r)
{
    vector<long long> answers(2);

    pair<int, int> left;
    pair<int, int> right;
    long long C = 0;
    long long K = 0;

    get_lr_pair(left, right, arr, l, r);
    K = get_sum(left, right, arr);

    if (l == r)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            if (K == arr[i])
            {
                C += arr[i];
            }
        }
    }
    else
    {
        r = r - l + 1;
        l = 1;

        get_lr_pair(left, right, arr, l, r);
        long long sum = get_sum(left, right, arr);
        long long diff = sum - K;

        move_pair(right, 1, arr[right.first]);
        // move_pair(left, 1, arr[left.first]);
        if (diff == 0)
        {
            C++;
        }

        while (right.first < arr.size())
        {

            int r_idx = right.first;
            int l_idx = left.first;

            long long dist = min(arr[r_idx] - right.second, arr[l_idx] - left.second) + 1;
            long long section_diff = arr[r_idx] - arr[l_idx];

            if (section_diff == 0)
            {
                if (diff == 0)
                {
                    C += dist;
                }
            }

            else
            {
                if (diff % section_diff == 0)
                {

                    long long multiple = -diff / section_diff;
                    if (multiple > 0 && multiple <= dist)
                    {
                        // cout << " add " <<endl;
                        C++;
                    }
                }
            }

            diff += section_diff * dist;

            move_pair(right, dist, arr[r_idx]);
            move_pair(left, dist, arr[l_idx]);
        }
    }

    answers[0] = K;
    answers[1] = C;

    return answers;
}