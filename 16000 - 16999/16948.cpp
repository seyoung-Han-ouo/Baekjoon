#include <iostream>
#include <queue>
using namespace std;

int N, r1, c1, r2, c2;
bool check[201][201];

void bfs();
bool canVisit(int r, int c);

void bfs() {
    queue<pair<pair<int, int>, int>> q;

    q.push({ { r1, c1 }, 0 });
    check[r1][c1] = true;

    while (!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        // 최종 목적지 도착
        if (r == r2 && c == c2) {
            cout << cnt << '\n';
            exit(0);
        }

        // 데스 나이트 이동 경우의 수
        int nr[6] = { r - 2, r - 2, r, r, r + 2, r + 2 };
        int nc[6] = { c - 1, c + 1, c - 2, c + 2, c - 1, c + 1 };

        for (int i = 0; i < 6; i++) {
            if (canVisit(nr[i], nc[i])) {
                q.push({ { nr[i], nc[i] }, cnt + 1 });
                check[nr[i]][nc[i]] = true;
            }
        }
    }
}

// 방문 가능 여부 체크
bool canVisit(int r, int c) {
    return ((r <= N && r >= 0) && (c <= N && c >= 0) && !check[r][c]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> r1 >> c1 >> r2 >> c2;

    bfs();

    cout << "-1\n";

    return 0;
}