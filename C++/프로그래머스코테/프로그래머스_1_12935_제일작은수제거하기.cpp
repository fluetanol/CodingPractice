#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr)
{

    int min_idx = 0;
    int min = 999999999;
    for (int i = 0; i < arr.size(); ++i)
    {
        if (arr[i] < min)
        {
            min_idx = i;
            min = arr[i];
        }
    }

    arr.erase(arr.begin() + min_idx);

    if (arr.size() == 0)
    {
        arr.push_back(-1);
    }

    return arr;
}