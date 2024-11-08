// 문제번호 : 1927번
// 최소힙
// 푼 시간 : 50분
// 알고리즘 분류 : 힙, 우선순위 큐

#include <iostream>
#include <vector>
using namespace std;

void Add(vector<int> &heap, int val)
{
    heap.push_back(val);
    int i = heap.size() - 1;
    while (true)
    {
        if (i == 0)
            break;
        else if (heap[i] < heap[i / 2])
        {
            swap(heap[i], heap[i / 2]);
        }
        else
        {
            break;
        }
        i /= 2;
    }
}

void Remove(vector<int> &heap)
{
    if (heap.size() == 1)
    {
        cout << 0 << "\n";
        return;
    }

    cout << heap[1] << "\n";
    heap[1] = heap.back();
    heap.pop_back();

    int i = 1;
    while (true)
    {
        int left = i * 2;
        int right = i * 2 + 1;

        // 자식 노드가 두 개 모두 다 있음
        if (right < heap.size())
        {
            if (heap[left] < heap[i] && heap[right] < heap[i])
            {
                if (heap[left] < heap[right])
                {
                    swap(heap[left], heap[i]);
                    i = left;
                }
                else
                {
                    swap(heap[right], heap[i]);
                    i = right;
                }
            }
            else if (heap[left] >= heap[i] && heap[right] < heap[i])
            {
                swap(heap[right], heap[i]);
                i = right;
            }
            else if (heap[left] < heap[i] && heap[right] >= heap[i])
            {
                swap(heap[left], heap[i]);
                i = left;
            }
            else
            {
                break;
            }
        }
        // 자식 노드가 하나만 있음
        else if (left < heap.size())
        {
            if (heap[left] < heap[i])
            {
                swap(heap[left], heap[i]);
            }
            break;
        }
        // 자식이 없는 리프임
        else
        {
            break;
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> heap(1);
    heap.reserve(n);

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (val != 0)
        {
            Add(heap, val);
        }
        else
        {
            Remove(heap);
        }
    }
}

/*
    위는 힙을 직접 구현한 방식이다. 그런데 어째 remove연산 안의 조건문이 
    너무 복잡해보인다...

*/

void Remove(vector<int> &heap)
{
    if (heap.size() == 1)
    {
        cout << 0 << "\n";
        return;
    }
    cout << heap[1] << "\n";
    heap[1] = heap.back();
    heap.pop_back();

    int i = 1;
    while (true)
    {
        int left = i * 2;
        int right = i * 2 + 1;
        int smallestidx = i;

        if (left < heap.size() && heap[left] < heap[smallestidx])
        {
            smallestidx = left;
        }

        if (right < heap.size() && heap[right] < heap[smallestidx])
        {
            smallestidx = right;
        }

        if (i == smallestidx)
            break;

        swap(heap[smallestidx], heap[i]);
        i = smallestidx;
    }
}

//이 버전으로 remove함수를 개선하는 것이 좋을듯 하다.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> heap;

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;

        if (val != 0)
        {
            heap.push(val);
        }
        else
        {
            if (heap.size() == 0)
                cout << 0 << "\n";
            else
            {
                cout << heap.top() << "\n";
                heap.pop();
            }
        }
    }
}

//위는 c++에서 제공하는 힙 사용법
//c++에서의 우선순위 큐 구현은 기본적으로 최대힙이다.
//최소힙을 구현하려면 greater<int>를 넣어주면 된다.
//참고로 명시적으로 최대힙 만들고 싶다면 less<int>를 넣어주면 된다.
//유용하니 사용법을 알아두자.