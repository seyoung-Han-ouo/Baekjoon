#include <stdio.h>

// �������ϱ�
int sum() {
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int n;
		scanf("%d", &n);

		sum += n;
	}

	return sum;
}

int main() {
	int sum1 = sum(); // �α����� ����
	int sum2 = sum(); // ������ ����

	if (sum1 < sum2) sum1 = sum2;

	printf("%d\n", sum1);

	return 0;
}