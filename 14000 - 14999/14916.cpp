#include <iostream>
using namespace std;

int findCnt(int n);

int findCnt(int n) {
	int five = n / 5;
	n %= 5;

	while (five > 0) {
		if (n % 2 == 0) return five + n / 2;

		n += 5;
		five--;
	}

	if (n % 2 == 0) return five + n / 2;

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	cout << findCnt(n) << '\n';

	return 0;
}