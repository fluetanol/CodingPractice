#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void DFS(int start, int node, vector<vector<int>>& adjlist, int**& visitedarr) {
    for (int i = 0; i < adjlist[node].size(); i++) {
  
        if (visitedarr[start][adjlist[node][i]] == 0) {
            visitedarr[start][adjlist[node][i]] = 1;
            DFS(start, adjlist[node][i], adjlist, visitedarr);
        }
    }
}
/*
    0 1 2 0



*/


int main()
{
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<vector<int>> adjlist(n);
    int** visitedarr = new int* [n];

    for (int i = 0; i < n; ++i) {
        visitedarr[i] = new int[n] {0};
        for (int j = 0; j < n; ++j) {
            int val = 0;
            cin >> val;
            if (val == 1) adjlist[i].push_back(j);
        }
    }


    for (int i = 0; i < n; ++i) {
        DFS(i, i,  adjlist, visitedarr);
    }



    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <n; ++j) {
            cout << visitedarr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; ++i) {
        delete[] visitedarr[i];
    }
    delete[] visitedarr;

   
}



/*
    그냥 무식하게 DFS로 풀음
    VISITED 체크하면서 가기 때문에 아무리 노드관계가 복잡해도 100 * 100 = 10000 정도
*/