#include <iostream>
using namespace std;

int main() {
	string nemo[51];

	int N, M; // N��Mũ���� ���簢��
	cin >> N >> M;

	// �Է�
	for (int i = 0; i < N; i++)
		cin >> nemo[i];

	int nemoSize = 1; // �׸��� ũ��

	// �������� ���� �ִ� ���� ��� ���� ���� ū ���簢���� ã��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c1 = nemo[i][j]; // ���簢���� ���� �� ������

			for (int k = j + 1; k < M; k++) {
				char c2 = nemo[i][k]; // ���簢���� ������ �� ������

				if (c1 == c2) {
					int idx = k - j; // ���簢���� �������� ������ �Ÿ�

					// ������ ���
					if (idx + i >= N) break;

					// ���� ã�Ҵ� �ͺ��� ū ���簢���� ã��
					if (nemo[idx + i][j] == c1 && nemo[idx + i][k] == c2 && idx + 1 > nemoSize)
						nemoSize = idx + 1;
				}
			}
		}
	}

	// ���
	printf("%d\n", nemoSize * nemoSize);

	return 0;
}