#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int N, R, Q;
int cnt[MAX];
vector<int> edge[MAX];

void dfs(int now, int parent);

void dfs(int now, int parent) {
    cnt[now] = 1;

    for (int node : edge[now]) {
        if (cnt[node] == 0) {
            dfs(node, now);
            
            cnt[now] += cnt[node];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> R >> Q;
    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;

        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dfs(R, 0);

    while (Q--) {
        int U;
        cin >> U;
        cout << cnt[U] << '\n';
    }

    return 0;
}