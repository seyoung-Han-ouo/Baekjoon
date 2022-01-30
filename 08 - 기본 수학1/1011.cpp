#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T; // 테스트케이스의 개수
	cin >> T;

	long long x, y; // 현재 위치 x, 목표 위치 y
	for (int i = 0; i < T; i++) {
		cin >> x >> y;

		if (sqrt(y - x) > round(sqrt(y - x)))
			cout << 2 * round(sqrt(y - x)) << '\n';
		else
			cout << 2 * round(sqrt(y - x)) -  1 << '\n';
	}

	return 0;
}