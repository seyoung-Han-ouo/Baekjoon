#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 32001

int N, M;
int inDegree[MAX];
vector<int> sq[MAX];

void topologicalSorting();

void topologicalSorting() {
    priority_queue<int> q;

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0) q.push(-i);

    while (!q.empty()) {
        int now = -q.top();
        q.pop();

        cout << now << ' ';

        for (int n : sq[now])
            if (--inDegree[n] == 0) q.push(-n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    while (M--) {
        int a, b;
        cin >> a >> b;

        sq[a].push_back(b);
        inDegree[b]++;
    }

    topologicalSorting();

    return 0;
}