#include <iostream>
using namespace std;

int N;
char arr[101][101];
bool check[101][101];

void dfs(int x, int y, char c);
int findCnt();

void dfs(int x, int y, char c) {
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (check[x][y] || arr[x][y] != c) return;

	if (arr[x][y] == 'R') arr[x][y] = 'G';

	check[x][y] = true;

	dfs(x + 1, y, c);
	dfs(x - 1, y, c);
	dfs(x, y + 1, c);
	dfs(x, y - 1, c);
}

int findCnt() {
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!check[i][j]) {
				cnt++;
				dfs(i, j, arr[i][j]);
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	cout << findCnt() << ' ';

	fill(&check[0][0], &check[100][100], false);

	cout << findCnt() << '\n';
	
	return 0;
}