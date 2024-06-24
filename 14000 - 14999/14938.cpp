#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

int n, m, r; // ������ ���� n, �������� �������� m, ���� ���� r 
int item[101];
vector<pair<int, int>> area[101];

int dijkstra(int start);

int dijkstra(int start) {
    vector<int> dist(n + 1, INF);

    priority_queue<pair<int, int>> q;
    q.push({ 0, start });
    dist[start] = 0;

    while (!q.empty()) {
        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();

        if (dist[now] < cost) continue;

        for (pair<int, int> ii : area[now]) {
            int nCost = cost + ii.first;

            if (nCost < dist[ii.second]) {
                dist[ii.second] = nCost;
                q.push({ -nCost, ii.second });
            }
        }
    }

    // ���� �� �ִ� �������� �� ���ϱ�
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= m) cnt += item[i];
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // �Է�
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++) cin >> item[i];
    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        area[a].push_back({ c, b });
        area[b].push_back({ c, a });
    }

    int result = 0;
    for (int i = 1; i <= n; i++) result = max(result, dijkstra(i));

    // ���
    cout << result << '\n';

    return 0;
}