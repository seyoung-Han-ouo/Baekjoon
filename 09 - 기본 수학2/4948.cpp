#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n = -1;

	while (true) {
		cin >> n;

		if (n == 0) break;

		int count = 0;
		// N + 1���� 2N������ ���� �߿��� �Ҽ��� ã�´�.
		for (int i = n + 1; i <= n * 2; i++) {
			if (i == 2 || i == 3)
				count++;
			// ¦���� �Ҽ��� �� �� ����.
			if (i % 2 == 0) continue;

			int num = sqrt(i);
			for (int j = 2; j <= num; j++) {
				// �Ҽ��� �ڱ��ڽŰ� 1�θ� ������ ���������Ѵ�.
				if (i % j == 0) break;
				// �Ҽ��� ã���� count�� ������Ų��.
				if (j == num)
					count++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}