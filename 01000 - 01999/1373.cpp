#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n; // 2����
	cin >> n;

	string num8 = ""; // 8����

	// ���� ��ȯ
	for (int i = n.length() - 1; i >= 0; ) {
		int sum = 0;

		// 2������ 3���� �ɰ��� ���� ��ȯ
		for (int j = 0; j < 3; j++) {
			if (i < 0) break;

			int num2 = n[i] - '0';

			sum += num2 * pow(2, j);
			i--;
		}

		// ��ȯ�� �� ��ġ��
		num8.append(to_string(sum));
	}

	// ���ڿ� ������
	reverse(num8.begin(), num8.end());

	// ���
	cout << num8 << endl;

	return 0;
}