#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	long long sum = 0;

	for (int i = 1; i <= N; i++) {
		int n = (N / i) * i;

		sum += n;
	}

	cout << sum << '\n';

	return 0;
}