#include <iostream>
using namespace std;

int people(int k, int n);

int people(int k, int n) {
	if (k == 0) return n; // 0���� nȣ���� n���� ���
	if (n == 1) return 1; // 1ȣ���� ������ 1�� ���.

	return people(k, n - 1) + people(k - 1, n);
}

int main() {
	// �׽�Ʈ ������ ��, k��, nȣ
	int T, k, n;

	cin >> T;
	for (int i = 0; i < T; i++) {
		// ������ �� �ޱ�
		cin >> k >> n;

		cout << people(k, n) << '\n';
	}
	
	return 0;
}