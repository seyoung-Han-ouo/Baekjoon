#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T; // �׽�Ʈ���̽��� ����
	cin >> T;

	long long x, y; // ���� ��ġ x, ��ǥ ��ġ y
	for (int i = 0; i < T; i++) {
		cin >> x >> y;

		if (sqrt(y - x) > round(sqrt(y - x)))
			cout << 2 * round(sqrt(y - x)) << '\n';
		else
			cout << 2 * round(sqrt(y - x)) -  1 << '\n';
	}

	return 0;
}