#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;

	while (cin >> n) {
		int idx = 1;
		int num = 1;

		while(true) {
			if (num % n == 0) break;

			idx++;
			num = num * 10 + 1;
			num %= n;
		}

		cout << idx << '\n';
	}

	return 0;
}