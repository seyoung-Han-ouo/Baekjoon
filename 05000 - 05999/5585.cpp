#include <iostream>
using namespace std;

int money[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, cnt = 0;
	cin >> n;

	n = 1000 - n;

	for (int i = 0; i < 6; i++) {
		cnt += (n / money[i]);
		n %= money[i];
	}

	cout << cnt << '\n';

	return 0;
}