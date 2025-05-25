#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;

	int cnt = 0;

	while (K--) {
		int a;
		cin >> a;

		cnt += (a / 2 + a % 2);
	}

	if (cnt >= N) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}