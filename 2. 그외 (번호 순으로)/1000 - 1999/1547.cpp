#include <iostream>
using namespace std;

int main() {
	int M; // ���� ��ġ�� �ٲ� Ƚ��
	cin >> M;

	int cup[3] = { 1, 2, 3 }; // ���� ��ġ

	for (int i = 0; i < M; i++) {
		int X, Y; // ���� ��ġ�� �ٲ� ��� X, Y
		scanf("%d %d", &X, &Y);

		// �ش� ��ȣ�� ���� ���� ��ġ ã��
		int idx1, idx2;
		for (int j = 0; j < 3; j++) {
			if (cup[j] == X) idx1 = j;
			if (cup[j] == Y) idx2 = j;
		}

		// �� ��ġ �ٲٱ�
		cup[idx1] = Y;
		cup[idx2] = X;
	}

	// ���
	cout << cup[0] << endl;

	return 0;
}