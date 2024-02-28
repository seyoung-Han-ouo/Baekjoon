#include <iostream>
using namespace std;

long long X, Y;

int binary(int Z);

int binary(int Z) {
	int low = 0;
	int high = 1000000000;
	int result = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int win = (Y + mid) * 100 / (X + mid);

		if (Z < win) 
			high = mid - 1;
		else
			result = low = mid + 1;
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> X >> Y;

	int Z = Y * 100 / X ;

	if (Z >= 99) 
		cout << "-1\n";
	else 
		cout << binary(Z) << '\n';

	return 0;
}