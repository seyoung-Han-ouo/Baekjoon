#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

#define INF 100000000

int n, m;
int sCity, eCity;
vector<pair<int, int>> bus[1001];
vector<int> last(1001);
vector<int> dist(1001, INF);

void dijkstra();

void dijkstra() {
	priority_queue<pair<int, int>> q;
	q.push({ 0, sCity });
	dist[sCity] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;

		q.pop();

		if (dist[now] < cost) continue;

		for (pair<int, int> ii : bus[now]) {
			int nCost = cost + ii.first;

			if (nCost < dist[ii.second]) {
				dist[ii.second] = nCost;
				last[ii.second] = now;
				q.push({ -nCost, ii.second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		bus[a].push_back({ c, b });
	}
	cin >> sCity >> eCity;

	dijkstra();

	stack<int> s;

	s.push(eCity);
	for (int i = eCity; ; ) {
		s.push(last[i]);
		i = last[i];

		if (i == sCity) break;
	}

	cout << dist[eCity] << '\n';
	cout << s.size() << '\n';

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}