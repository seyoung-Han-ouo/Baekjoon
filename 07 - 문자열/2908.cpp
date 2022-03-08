#include <iostream>
using namespace std;

int main() {
	// 상근이가 칠판에 적은 두 수 A와 B
	string A, B;
	cin >> A >> B;

	// 일의 자리부터 두 수를 비교한다.
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