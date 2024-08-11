#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 1001

int N, K, W; // 건물의 개수 N, 규칙의 개수 K, 승리하기 위해 건설해야 할 건물의 번호 W
int result[MAX];
int inDegree[MAX];
int buildTime[MAX];
vector<int> sq[MAX];

int topologicalSorting();

int topologicalSorting() {
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);

        result[i] = buildTime[i];
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int n : sq[now]) {
            if (--inDegree[n] == 0) q.push(n);

            result[n] = max(result[n], result[now] + buildTime[n]);
        }
    }

    return result[W];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        cin >> N >> K;
        for (int i = 1; i <= N; i++) cin >> buildTime[i];

        while (K--) {
            int a, b;
            cin >> a >> b;

            sq[a].push_back(b);
            inDegree[b]++;
        }
        cin >> W;

        cout << topologicalSorting() << '\n';

        for (int i = 1; i <= N; i++) sq[i].clear();
    }

    return 0;
}