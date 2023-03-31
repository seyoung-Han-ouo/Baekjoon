#include <iostream>
using namespace std;

int black(int a, int b);

bool paper[100][100] = { false };

// �̹� �����̷� ���� ���� ������ ����
int black(int a, int b) {
	int count = 0; // ���� ������ ����

	for (int i = a; i < a + 10; i++) {
		for (int j = b; j < b + 10; j++) {
			if (!paper[i][j]) {
				paper[i][j] = true;
				count++;
			}
		}
	}

	return count;
}

int main() {
	int n; // �������� ��
	scanf("%d", &n);

	int blackNum = 0; // �����̰� ���� ���� ������ ����

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		blackNum += black(a, b);
	}

	printf("%d\n", blackNum);

	return 0;
}