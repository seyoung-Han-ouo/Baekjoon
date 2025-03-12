#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

int N, M;
int edge[201][201];
vector<vector<int>> dist(201, vector<int>(201, INF));

double burn();

double burn() {
	double result = INF;

	for (int start = 0; start < N; start++) {
		double time = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (edge[i][j] == 0) continue;

				double remain = edge[i][j] - (dist[start][j] - dist[start][i]);

				if (remain > 0) time = max((remain / 2 + dist[start][j]), time);
			}
		}

		result = min(result, time);
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) dist[i][i] = 0;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		a--;
		b--;

		dist[a][b] = dist[b][a] = min(dist[a][b], c);
		edge[a][b] = edge[b][a] = max(edge[a][b], c);
	}

	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	cout << fixed;
	cout.precision(1);
	cout << burn() << '\n';

	return 0;
}