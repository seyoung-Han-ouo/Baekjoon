#include <iostream>
using namespace std;

int main() {
	int N; // �ڿ��� N
	cin >> N;

	// N�� ���� ���� �����ڸ� ���Ѵ�.
	for (int i = 0; i <= N; i++) {
		// i�� ������ sum�� ���Ѵ�.
		int j = i, sum = i;
		while (j > 0) {
			sum += (j % 10);
			j /= 10;
		}

		// sum�� N�� ������ i�� ����Ѵ�.
		if (sum == N) {
			cout << i;
			break;
		}

		// i�� N�� ������ 0�� ����Ѵ�.
		if (i == N)
			cout << 0;
	}

	return 0;
}