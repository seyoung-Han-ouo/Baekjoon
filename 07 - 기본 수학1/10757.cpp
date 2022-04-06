#include <iostream>
#include<algorithm>
#include <string>

using namespace std;

int main() {
	string A, B, C;
	cin >> A >> B;

	// 입력 받은 수 중에서 큰 수를 A로 설정한다.
	if (A.length() < B.length()) {
		C = A;
		A = B;
		B = C;
	}

	// 편한 계산을 위해 문자열을 뒤집는다.
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int* add = new int[A.length() + 1];

	int up = 0; // 받아올림이 있는지를 확인하는 변수
	for (int i = 0; i < A.length(); i++) {
		int a = A[i] - '0';
		int b = 0;

		if (i < B.length())
			b = B[i] - '0';

		add[i] = (up + (a + b)) % 10;
		up = (up + (a + b)) / 10;
	}

	// 출력
	if (up != 0) cout << up;
	for (int i = 0; i < A.length(); i++)
		cout << add[A.length() - i - 1];

	return 0;
}