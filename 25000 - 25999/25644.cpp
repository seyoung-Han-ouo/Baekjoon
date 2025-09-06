#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	int result = 0;
	int mn = 1000000001;

	while (N--) {
		int n;
		cin >> n;

		mn = min(n, mn);
		result = max(n - mn, result);
	}

	cout << result << '\n';

	return 0;
}