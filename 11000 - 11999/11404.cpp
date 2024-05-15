#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

vector<vector<int>> bus(100, vector<int>(100, INF));

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		bus[a - 1][b - 1] = min(bus[a - 1][b - 1], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				bus[i][j] = min(bus[i][j], bus[i][k] + bus[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (bus[i][j] == INF || i == j) 
				cout << "0 ";
			else 
				cout << bus[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}