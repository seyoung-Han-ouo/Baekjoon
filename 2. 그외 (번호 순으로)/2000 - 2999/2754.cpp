#include <iostream>
using namespace std;

int main() {
	char sign[3] = {'+', '0', '-'}; // ������ ��ȣ
	double score[3] = { 4.3, 4.0, 3.7 }; // �� ��ȣ�� �ְ� ����

	string c;
	cin >> c;

	double num = 0; // ����

	// ���� ���ϱ�
	if (c[0] != 'F') {
		int i;
		for (i = 0; i < 3; i++)
			if (sign[i] == c[1]) break;

		int n = c[0] - 'A';
		num = score[i] - n;
	}

	// �Ҽ��� �ڸ� ����
	cout << fixed;
	cout.precision(1);

	// ���
	cout << num << endl;
	
	return 0;
}