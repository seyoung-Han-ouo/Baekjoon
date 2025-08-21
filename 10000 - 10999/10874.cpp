#include <iostream>
using namespace std;

bool check();

bool check() {
	bool result = true;

	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;

		if (i % 5 + 1 != n) result = false;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		if (check()) cout << i + 1 << '\n';
	}

	return 0;
}