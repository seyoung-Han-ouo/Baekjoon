#include <iostream>
using namespace std;

int main() {
	int N, L; // �� N, ���� L
	cin >> N >> L;

	int num = 0;
	for (int i = 0; i < L; i++)
		num += i;

	// �Էµ� L���� �� ������ �ʿ��� ��
	if ((N - num) % L != 0 || (N - num) / L < 0) {
		for (int i = 0; ; i++) {
			num += L;
			L++;

			// ������ ���� ��
			if (L > 100) {
				L = -1;
				break;
			}

			// ������ ã���� ��
			if ((N - num) % L == 0 && (N - num) / L >= 0)
				break;
		}
	}

	// ���
	if (L == -1)
		printf("-1");
	else
		for (int i = 0; i < L; i++)
			printf("%d ", ((N - num) / L) + i);
	printf("\n");

	return 0;
}