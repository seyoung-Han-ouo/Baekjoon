#include <iostream>
using namespace std;

int A, B, C;
bool check[201][201][201];

void dfs(int a, int b, int c);

void dfs(int a, int b, int c) {
	if (check[a][b][c]) return;

	check[a][b][c] = true;

	dfs(a - min(a, B - b), b + min(a, B - b), c);
	dfs(a - min(a, C - c), b, c + min(a, C - c));
	dfs(a + min(b, A - a), b - min(b, A - a), c);
	dfs(a, b - min(b, C - c), c + min(b, C - c));
	dfs(a + min(c, A - a), b, c - min(c, A - a));
	dfs(a, b + min(c, B - b), c - min(c, B - b));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B >> C;

	dfs(0, 0, C);

	for (int i = 0; i <= C; i++) {
		for (int j = 0; j <= B; j++) {
			if (check[0][j][i]) cout << i << ' ';
		}
	}

	return 0;
}