#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

bool check[10000];

void bfs(int A, int B);

void bfs(int A, int B) {
	queue<pair<int, string>> q;

	q.push({ A, "" });
	check[A] = true;

	while (!q.empty()) {
		int n = q.front().first;
		string s = q.front().second;
		q.pop();

		if (n == B) {
			cout << s << '\n';
			return;
		}

		int D = (n * 2) % 10000;
		if (!check[D]) {
			q.push({ D, s + "D" });
			check[D] = true;
		}

		int S = (n - 1 < 0) ? 9999 : n - 1;
		if (!check[S]) {
			q.push({ S, s + "S" });
			check[S] = true;
		}

		int L = (n % 1000) * 10 + (n / 1000);
		if (!check[L]) {
			q.push({ L, s + "L" });
			check[L] = true;
		}

		int R = (n % 10) * 1000 + (n / 10);
		if (!check[R]) {
			q.push({ R, s + "R" });
			check[R] = true;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int A, B;
		cin >> A >> B;

		bfs(A, B);
		fill_n(check, 10000, false);
	}

	return 0;
}