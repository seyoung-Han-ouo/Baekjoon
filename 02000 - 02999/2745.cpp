#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string N; // B���� �� 
	int B; // B����
	cin >> N >> B;

	int result = 0; // 10�������� ��ȯ�� ���
	int j = 0;

	for (int i = N.length() - 1; i >= 0; i--) {
		int num;

		// N�� �� �ڸ����� int��
		if (N[i] >= 'A' && N[i] <= 'z')
			num = N[i] - 'A' + 10;
		else
			num = N[i] - '0';

		result += (num * pow(B, j++));
	}

	printf("%d\n", result);

	return 0;
}