#include <iostream>
using namespace std;

int main() {
	// ����̰� ĥ�ǿ� ���� �� �� A�� B
	string A, B;
	cin >> A >> B;

	// ���� �ڸ����� �� ���� ���Ѵ�.
	for (int i = 2; i >= 0; i--) {
		if (A[i] < B[i]) {
			cout << B[2] << B[1] << B[0];
			break;
		}
		else if (A[i] > B[i]) {
			cout << A[2] << A[1] << A[0];
			break;
		}
	}


	return 0;
}