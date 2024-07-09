#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[32001];
vector<int> student[32001];

void topologicalSorting();

void topologicalSorting() {
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0) q.push(i);

    for (int i = 0; i < N; i++) {
        int now = q.front();
        q.pop();

        cout << now << ' ';

        for (int n : student[now])
            if (--inDegree[n] == 0) q.push(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        student[a].push_back(b);
        inDegree[b]++;
    }

    topologicalSorting();

    return 0;
}