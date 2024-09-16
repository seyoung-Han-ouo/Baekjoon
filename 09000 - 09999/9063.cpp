#include <iostream>
using namespace std;

int N;
int minX = 10001, maxX = -10001;
int minY = 10001, maxY = -10001;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}

	cout << (maxX - minX) * (maxY - minY) << '\n';

	return 0;
}