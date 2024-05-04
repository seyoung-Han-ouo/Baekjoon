#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1000000
#define SIZE 20001

vector<vector<pair<int, int>>> weight(SIZE);
vector<int> dist(SIZE, INF);

void dijkstra(int start);

void dijkstra(int start) {
    priority_queue<pair<int, int>> q;

    q.push({ 0, start });
    dist[start] = 0;

    while (!q.empty()) {
        int now = q.top().second;
        int w = -q.top().first;
        q.pop();

        // 이미 최단거리일 때
        if (dist[now] < w) continue;

        for (pair<int, int> ii : weight[now]) {
            int nw = w + ii.first;

            // dist 갱신
            if (nw < dist[ii.second]) {
                dist[ii.second] = nw;
                q.push({ -nw, ii.second }); // 내림차순 정렬이기에
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int V, E, K;

    // 입력
    cin >> V >> E >> K;
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        weight[u].push_back({ w, v });
    }

    dijkstra(K);

    // 출력
    for (int i = 1; i <= V; i++) {
        if (dist[i] == INF) 
            cout << "INF\n";
        else 
            cout << dist[i] << '\n';
    }

    return 0;
}