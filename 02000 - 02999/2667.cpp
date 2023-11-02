#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool arr[25][25];
vector<int> house;

void dfs(int x, int y);

void dfs(int x, int y) {
	if (!arr[x][y] || x < 0 || y < 0 || x >= N || y >= N) return;

	arr[x][y] = false;
	house[house.size() - 1]++;

	dfs(x + 1, y);
	dfs(x - 1, y);
	dfs(x, y + 1);
	dfs(x, y - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) arr[i][j] = s[j] - '0';
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j]) {
				house.push_back(0);
				dfs(i, j);
			}
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << '\n';
	for (int i = 0; i < house.size(); i++) cout << house[i] << '\n';

	return 0;
}