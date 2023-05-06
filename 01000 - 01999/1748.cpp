#include <iostream>
using namespace std;

int countLen(int N);

// �ڸ��� ���ϱ�
int countLen(int N) {
	int len = 0; // �ڸ���
	int cnt = 1; // �� ������ �ڸ���
	int useNum = 0; // �ڸ����� �� ������ ����

	for (int i = 10; i <= N; i *= 10) {
		int n = i - (i / 10);

		len += n * cnt++;
		useNum += n;
	}

	if (useNum != N)
		len += (N - useNum) * cnt;

	return len;
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", countLen(N));

	return 0;
}