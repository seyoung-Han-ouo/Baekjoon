#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N; // �������� �� N
	int jimin, hansoo; // �������� ��ȣ, ���Ѽ��� ��ȣ

	// �Է�
	cin >> N >> jimin >> hansoo;

	for (int i = 1; ; i++) {
		int n = pow(2, i);

		// �����ΰ� ���Ѽ��� ����ϴ°�?
		if ((jimin - 1) / n == (hansoo - 1) / n) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}