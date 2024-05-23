#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 10001

vector<int> arr[MAX];
bool check[MAX];
int result[MAX];

int bfs(int start);

int bfs(int start) {
    int cnt = 0;

    queue<int> q;
    q.push(start);
    check[start] = true;

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int n : arr[now]) {
            if (!check[n]) {
                q.push(n);
                check[n] = true;
            }
        }

        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        arr[b].push_back(a);
    }

    int mx = 0;

    for (int i = 1; i <= N; i++) {
        result[i] = bfs(i);

        mx = max(mx, result[i]);

        fill(check, check + MAX, false);
    }

    for (int i = 1; i <= N; i++) {
        if (result[i] == mx) cout << i << ' ';
    }
    cout << '\n';

    return 0;
}