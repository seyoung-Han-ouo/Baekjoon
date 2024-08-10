#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int inDegree[1001];
vector<int> gasu[1001];
vector<int> result;

void topologicalSorting();

void topologicalSorting() {
    queue<int> q;

    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        result.push_back(now);

        for (int n : gasu[now])
            if (--inDegree[n] == 0) q.push(n);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    while (M--) {
        int n;
        cin >> n;

        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                gasu[v[i]].push_back(v[j]);
                inDegree[v[j]]++;
            }
        }
    }

    topologicalSorting();

    if (result.size() != N) cout << "0\n";
    else for (int n : result) cout << n << '\n';

    return 0;
}