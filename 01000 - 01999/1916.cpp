#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, start, ed;
int dp[1001];
vector<pair<int, int>> bus[1001];

void dijkstra();

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });
    dp[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dp[now] < cost) continue;

        for (int i = 0; i < bus[now].size(); i++) {
            int next = bus[now][i].first;
            int nextCost = dp[now] + bus[now][i].second;

            if (nextCost < dp[next]) {
                dp[next] = nextCost;
                pq.push({ nextCost, next });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    fill_n(dp, 1001, 100000000);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        bus[a].push_back({ b, c });
    }

    cin >> start >> ed;

    dijkstra();

    cout << dp[ed] << '\n';

    return 0;
}