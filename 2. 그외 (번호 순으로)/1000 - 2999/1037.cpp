#include <iostream>
using namespace std;

int main() {
	int count; // N�� ��¥ ����� ����
	cin >> count;

	int small = 1000000; // ��� �� ���� ���� ��
	int big = 2; // ��� �� ���� ū ��

	for (int i = 0; i < count; i++) {
		int divisor; // N�� ��¥ ���
		scanf("%d", &divisor);

		// ���� ū �� ã��
		if (divisor > big)
			big = divisor;

		// ���� ���� �� ã��
		if (divisor < small)
			small = divisor;
	}

	// ���
	cout << big * small << endl;

	return 0;
}