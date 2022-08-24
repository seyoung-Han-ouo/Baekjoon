#include <iostream>
using namespace std;

int main() {
	// N��° ��ȭ�� ����
	int N;
	cin >> N;

	if (N <= 6)
		cout << (N - 1) * 1000 + 666;
	else {
		// �ð��� ���̱� ���� i�� 6660���� ����
		// count�� 6�� 3�� ���� ������ ���ڰ� ���°������ ����
		int i, count = 6;
		for (i = 6660; count < N; i++) {
			// i�� 6�� 3�� ���� �������� Ȯ��
			int j = i, is6 = 0;
			while (j > 0) {
				if (is6 == 3)
					break;
				else if (j % 10 == 6)
					is6++;
				else
					is6 = 0;

				j /= 10;
			}

			if (is6 == 3)
				count++;

			if (count == N)
				cout << i;
		}
	}

	return 0;
}