#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 200000000

vector<pair<int, int>> edge[801];
vector<int> dist[3];

void dijkstra(int start, int idx);

void dijkstra(int start, int idx) {
    priority_queue<pair<int, int>> q;

    q.push({ 0, start });
    dist[idx][start] = 0;

    while (!q.empty()) {
        int now = q.top().second;
        int w = -q.top().first;

        q.pop();

        if (dist[idx][now] < w) continue;

        for (pair<int, int> ii : edge[now]) {
            int nw = w + ii.first;

            if (nw < dist[idx][ii.second]) {
                dist[idx][ii.second] = nw;
                q.push({ -nw, ii.second });
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, E; // 정점의 개수 N, 간선의 개수 E
    int v1, v2;

    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge[a].push_back({ c, b });
        edge[b].push_back({ c, a });
    }
    cin >> v1 >> v2;

    for (int i = 0; i < 3; i++)
        dist[i].resize(N + 1, INF);

    dijkstra(1, 0);
    dijkstra(v1, 1);
    dijkstra(v2, 2);

    int result = min(dist[0][v1] + dist[1][v2] + dist[2][N], dist[0][v2] + dist[2][v1] + dist[1][N]);

    if (result >= INF) 
        cout << "-1\n";
    else
        cout << result << '\n';

    return 0;
}