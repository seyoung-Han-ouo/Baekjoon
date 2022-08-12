#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int L; // ���� S�� ũ�� L
	int S[51]; // ���տ� ���Ե� ����
	int n; // ������ ���ԵǾ�� �ϴ� ����

	// �Է�
	cin >> L;
	for (int i = 0; i < L; i++)
		cin >> S[i];
	cin >> n;

	// ����
	sort(S, S + L);

	int idx = -2;

	// n���� ���� ���� �߿��� n�� ���� ����� ���� ��ġ ã��
	for (int i = 0; i < L; i++) {
		// n�� ���� S�� ���� ��
		if (S[i] == n) {
			idx = -1;
			break;
		}

		if (S[i] < n) idx = i;
	}

	int count = 0; // n�� �����ϴ� ���� ������ ����

	if (idx != -1) {
		int start = 1; // ������ ���Ե� �� �ִ� ���� ���� ��
		int end = S[0] - 1; // ������ ���Ե� �� �ִ� ���� ū ��

		if (idx >= 0) {
			start = S[idx] + 1;
			end = S[idx + 1] - 1;
		}

		// n�� �����ϴ� ���� ������ ���� ã��
		for (int i = 0; ; i++) {
			if (start + i > n) break;

			count += (end - n + 1);
		}

		count--;
	}

	// ���
	printf("%d\n", count);
	
	return 0;
}