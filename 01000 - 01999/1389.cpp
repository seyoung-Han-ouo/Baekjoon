#include <iostream>
#include <queue>
using namespace std;

int N, M;
bool arr[101][101];
queue<int> q;

int bfs(int n) {
	int cnt[101] = { 0 };
	bool check[101] = { false };

	q.push(n);
	check[n] = true;

	while (!q.empty()) {
		int user = q.front();
		q.pop();

		for (int i = 1; i <= N; i++) {
			if (arr[user][i] && !check[i]) {
				cnt[i] = cnt[user] + 1;

				q.push(i);
				check[i] = true;
			}
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) sum += cnt[i];

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;

		arr[a][b] = arr[b][a] = true;
	}

	int result = 0;
	int mn = 99999999999999;

	for (int i = 1; i <= N; i++) {
		int find = bfs(i);

		if (find < mn) {
			result = i;
			mn = find;
		}
	}

	cout << result << '\n';
	
	return 0;
}