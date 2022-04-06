#include <iostream>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B;

	// �Է� ���� �� �߿��� ū ���� A�� �����Ѵ�.
	if (A.length() < B.length()) {
		C = A;
		A = B;
		B = C;
	}

	// ���� ����� ���� ���ڿ��� �����´�.
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int* add = new int[A.length() + 1];

	int up = 0; // �޾ƿø��� �ִ����� Ȯ���ϴ� ����
	for (int i = 0; i < A.length(); i++) {
		int a = A[i] - '0';
		int b = 0;

		if (i < B.length())
			b = B[i] - '0';

		add[i] = (up + (a + b)) % 10;
		up = (up + (a + b)) / 10;
	}

	// ���
	if (up != 0) cout << up;
	for (int i = 0; i < A.length(); i++)
		cout << add[A.length() - i - 1];

	return 0;
}