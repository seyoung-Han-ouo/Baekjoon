#include <iostream>
#include <queue>
using namespace std;

#define INF 1000000

int cave[125][125];
int dist[125][125];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

void dijkstra(int N);

void dijkstra(int N) {
    priority_queue<pair<int, pair<int, int>>> q;

    q.push({ -cave[0][0], { 0, 0 } });
    dist[0][0] = cave[0][0];

    while (!q.empty()) {
        int x = q.top().second.first;
        int y = q.top().second.second;
        int w = -q.top().first;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 체크
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            int nw = w + cave[ny][nx];

            // dist 갱신
            if (nw < dist[ny][nx]) {
                dist[ny][nx] = nw;
                q.push({ -nw, { nx, ny } });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int cnt = 1;

    while (true) {
        int N;
        cin >> N;

        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> cave[i][j];

                dist[i][j] = INF; // dist 초기화
            }
        }

        dijkstra(N);

        cout << "Problem " << cnt++ << ": " << dist[N - 1][N - 1] << '\n';
    }
    
    return 0;
}