#include <iostream>
using namespace std;

int main() {
	int A, B; // ���� A, �� B
	cin >> A >> B;

	int num = 1; // ������ ����
	int sum = 0; // ������ ��

	// A��° ���ں��� B��° ���ڱ��� �� ���ϱ�
	for (int i = 1; i <= B; ) {
		for (int j = 1; j <= num; j++) {
			if (i > B) break;

			if (i >= A) sum += num;

			i++;
		}
		num++;
	}

	// ���
	cout << sum << endl;

	return 0;
}