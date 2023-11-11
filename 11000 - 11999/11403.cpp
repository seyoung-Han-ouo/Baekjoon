#include <iostream>
#include <vector>
using namespace std;

bool check[100][100];
vector<int> v[100];

void dfs(int now, int x);

void dfs(int now, int x) {
	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		if (!check[now][y]) {
			check[now][y] = true;
			dfs(now, y);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;

			if (n) v[i].push_back(j);
		}
	}

	for (int i = 0; i < N; i++) dfs(i, i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cout << check[i][j] << ' ';
		cout << '\n';
	}
	
	return 0;
}