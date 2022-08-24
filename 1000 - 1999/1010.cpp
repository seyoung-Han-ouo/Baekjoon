#include <iostream>
using namespace std;

// ����
int combination(int M, int N) {
	long int num1 = 1; // ����
	long int num2 = 1; // �и�

	for (int i = 0; i < N; i++) {
		num1 *= M--;
		num2 *= (i + 1);

		// int ������ �Ѿ�� ���� ���� ���� ���
		if (num1 % (i + 1) == 0 && num2 % (i + 1) == 0) {
			num1 /= (i + 1);
			num2 /= (i + 1);
		}
	}

	return num1 / num2;
}

int main() {
	int T; // �׽�Ʈ ���̽��� ���� 
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M; // ���� ���ʰ� ���ʿ� �ִ� ����Ʈ�� ���� (N �� M)
		scanf("%d %d", &N, &M);

		// ���
		cout << combination(M, N) << endl;
	}
	return 0;
}