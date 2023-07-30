#include <iostream>
using namespace std;

int f[1000001];
long long g[1000001] = { 0 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i < 1000001; i++) {
		for (int j = i; j < 1000001; j += i) f[j] += i;

		g[i] = g[i - 1] + f[i];
	}

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;

		cout << g[N] << '\n';
	}

	return 0;
}