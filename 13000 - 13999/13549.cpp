#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100000

bool check[MAX + 1];

void bfs(int start, int end);

void bfs(int start, int end) {
    queue<pair<int, int>> q;

    q.push({ start, 0 });
    check[start] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        if (x == end) {
            cout << time << '\n';
            return;
        }

        int nx[3] = { x * 2, x - 1, x + 1 };         // 다음 위치
        int ntime[3] = { time, time + 1, time + 1 }; // 다음 위치에 도달하는데 걸리는 시간

        for (int i = 0; i < 3; i++) {
            if (nx[i] <= MAX && nx[i] >= 0 && !check[nx[i]]) {
                q.push({ nx[i], ntime[i] });
                check[nx[i]] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    bfs(N, K);

    return 0;
}