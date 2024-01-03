#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 100001

int mn = MAX, cnt;
bool check[MAX];

void bfs(int start, int end);

void bfs(int start, int end) {
    queue<pair<int, int>> q;

    q.push({ start, 0 });
    check[start] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        check[x] = true;

        // 최종 목적지 도착
        if (x == end) {
            mn = min(time, mn);

            if (time == mn) cnt++;
        }

        // 세 가지 경우의 수
        int nx[3] = { x * 2, x - 1, x + 1 };

        for (int i = 0; i < 3; i++) {
            if (nx[i] < MAX && nx[i] >= 0 && !check[nx[i]])
                q.push({ nx[i], time + 1 });
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

    cout << mn << '\n' << cnt << '\n';

    return 0;
}