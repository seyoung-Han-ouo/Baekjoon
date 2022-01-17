#include <iostream>
using namespace std;

int main() {
	int N, M, count = 0;
	cin >> N;

	// N만큼 숫자를 입력받는다.
	for (int i = 0; i < N; i++) {
		cin >> M;

		// 1은 소수가 아니다.
		if (M != 1) {
			for (int i = 2; i <= M; i++) {
				if (i == M) count++;
				if (M % i == 0) break; // 소수는 자기자신과 1만으로만 나누어 떨어져야한다.
			}
		}
	}

	cout << count;

	return 0;
}