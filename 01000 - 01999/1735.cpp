#include <iostream>
using namespace std;

struct bunsoo {
	int A; // ����
	int B; // �и�
};

int GCD(int a, int b);

// ��Ŭ���� ȣ�������� �ִ����� ���ϱ�
int GCD(int a, int b) {
	while (b != 0) {
		int n = a % b;

		a = b;
		b = n;
	}

	return a;
}

int main() {
	bunsoo n1, n2, result;
	scanf("%d %d %d %d", &n1.A, &n1.B, &n2.A, &n2.B);

	// �� �м��� ��
	result.A = n1.A * n2.B + n2.A * n1.B;
	result.B = n1.B * n2.B;

	int n = GCD(result.A, result.B);

	printf("%d %d\n", result.A / n, result.B / n);

	return 0;
}