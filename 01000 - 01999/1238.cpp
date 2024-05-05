#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 2000000

vector<pair<int, int>> road[2][1001];
vector<int> dist[2];

void dijkstra(int start, int x);

void dijkstra(int start, int x) {
    priority_queue<pair<int, int>> q;

    q.push({ 0, x });
    dist[start][x] = 0;

    while (!q.empty()) {
        int now = q.top().second;
        int time = -q.top().first;
        q.pop();

        if (dist[start][now] < time) continue;

        for (pair<int, int> ii : road[start][now]) {
            int ntime = time + ii.first;

            if (ntime < dist[start][ii.second]) {
                dist[start][ii.second] = ntime;
                q.push({ -ntime, ii.second });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, X;
    cin >> N >> M >> X;

    for (int i = 0; i < M; i++) {
        int s, e, t;
        cin >> s >> e >> t;

        road[0][s].push_back({ t, e });
        road[1][e].push_back({ t, s });
    }

    dist[0].resize(N + 1, INF);
    dist[1].resize(N + 1, INF);

    dijkstra(0, X);
    dijkstra(1, X);

    int result = 0;

    for (int i = 1; i <= N; i++)
        result = max(result, dist[0][i] + dist[1][i]);

    cout << result << '\n';

    return 0;
}