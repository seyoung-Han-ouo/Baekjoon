#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

struct Edge {
    int end = 0;
    int time = 0;
};

int N, M, W;
vector<Edge> edge[500];
vector<int> dist;

bool bellmanFord();

bool bellmanFord() {
    dist[0] = 0;

    for (int n = 0; n < N; n++) {
        int isUpdate = false;

        for (int i = 0; i < N; i++) {
            for (Edge e : edge[i]) {
                int end = e.end;
                int time = e.time;

                if (dist[i] + time < dist[end]) {
                    dist[end] = dist[i] + time;
                    isUpdate = true;
                }
            }
        }

        if (!isUpdate) return false;
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int TC;
    cin >> TC;

    while (TC--) {
        cin >> N >> M >> W;

        for (int i = 0; i < N; i++) edge[i].clear();
        dist.resize(N, INF);

        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            edge[a - 1].push_back({ b - 1, c });
            edge[b - 1].push_back({ a - 1, c });
        }

        for (int i = 0; i < W; i++) {
            int a, b, c;
            cin >> a >> b >> c;

            edge[a - 1].push_back({ b - 1, -c });
        }

        // Ãâ·Â
        if (bellmanFord()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}