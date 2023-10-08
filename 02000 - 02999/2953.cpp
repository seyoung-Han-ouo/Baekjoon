#include <iostream>
using namespace std;

int main() {
	int max = 0, num = 0;

	for (int i = 0; i < 5; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int sum = a + b + c + d;

		if (sum > max) {
			max = sum;
			num = i;
		}
	}

	cout << num + 1 << " " << max << '\n';

	return 0;
}