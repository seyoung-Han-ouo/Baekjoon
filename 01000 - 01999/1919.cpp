#include <iostream>
using namespace std;

int main() {
	string a, b; // �� ���� �ܾ�

	cin >> a >> b;

	int count = 0; // �� ���� �ܾ ��� ���ԵǴ� ������ ��

	// �� ���� �ܾ ��� ���ԵǴ� ������ �� ���ϱ�
	for (int i = 0; i < a.length(); i++) {
		for (int j = 0; j < b.length(); j++) {
			if (a[i] == b[j]) {
				b[j] = 'A';
				count++;
				break;
			}
		}
	}

	// ���
	printf("%d\n", (a.length() - count) + (b.length() - count));

	return 0;
}