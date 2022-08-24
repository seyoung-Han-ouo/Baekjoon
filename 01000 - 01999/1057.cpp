#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N; // 참가자의 수 N
	int jimin, hansoo; // 김지민의 번호, 임한수의 번호

	// 입력
	cin >> N >> jimin >> hansoo;

	for (int i = 1; ; i++) {
		int n = pow(2, i);

		// 김지민과 임한수가 대결하는가?
		if ((jimin - 1) / n == (hansoo - 1) / n) {
			cout << i << endl;
			break;
		}
	}

	return 0;
}