#include <iostream>
#include <vector>
using namespace std;

#define INF 100000000

struct Bus {
    long long start = 0;
    long long end = 0;
    long long time = 0;
};

int N, M;
vector<Bus> bus;
vector<long long> dist(500, INF);

bool bellmanFord();

bool bellmanFord() {
    dist[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int start = bus[j].start;
            int end = bus[j].end;
            int time = bus[j].time;

            // 한 번이라도 계산된 적이 있는 정점이어야 한다.
            if (dist[start] == INF) continue;

            if (dist[start] + time < dist[end]) {
                dist[end] = dist[start] + time; // dist 갱신

                // N번째에서 값이 갱신된다면 음수 사이클이 존재한다는 것임
                if (i == N - 1) return true;
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        bus.push_back({ a - 1, b - 1, c });
    }

    if (bellmanFord()) cout << "-1\n";
    else {
        for (int i = 1; i < N; i++) {
            if (dist[i] == INF) 
                cout << "-1\n";
            else 
                cout << dist[i] << '\n';
        }
    }
    
    return 0;
}