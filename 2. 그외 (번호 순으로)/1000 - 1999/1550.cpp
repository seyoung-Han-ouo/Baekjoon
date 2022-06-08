#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	string n; // 16���� ��
	cin >> n;

	reverse(n.begin(), n.end());

	int ten = 0; // 10����

	// 16������ ���� 10������ ��ȯ�ϱ�
	for (int i = 0; i < n.length(); i++) {
		if (i >= n.length()) break;

		int num = n[i] - '0';

		if (n[i] >= 'A')
			num = n[i] - 'A' + 10;

		ten += (num * pow(16, i));
	}

	// ���
	cout << ten << endl;

	return 0;
}