#include <iostream>
using namespace std;

int main() {
	int N, M; // �ڽ��� ���� N, å�� ���� M
	cin >> N >> M;

	int* box = new int[N]; // �ڽ��� �뷮

	// �ڽ��� �뷮 �Է�
	for (int i = 0; i < N; i++)
		scanf("%d", &box[i]);

	// å �ֱ�
	for (int i = 0; i < M; i++) {
		int book;
		scanf("%d", &book);

		for (int j = 0; j < N; j++) {
			if (book <= box[j]) {
				box[j] -= book;
				break;
			}
		}
	}
		
	// �ڽ��� ����� �뷮
	int waste = 0;
	for (int i = 0; i < N; i++)
		waste += box[i];

	// ���
	cout << waste << endl;

	return 0;
}