#include <iostream>
using namespace std;

int main() {
	int N; // 자연수 N
	cin >> N;

	// N의 가장 작은 생성자를 구한다.
	for (int i = 0; i <= N; i++) {
		// i의 분해합 sum을 구한다.
		int j = i, sum = i;
		while (j > 0) {
			sum += (j % 10);
			j /= 10;
		}

		// sum이 N과 같으면 i를 출력한다.
		if (sum == N) {
			cout << i;
			break;
		}

		// i가 N과 같으면 0을 출력한다.
		if (i == N)
			cout << 0;
	}

	return 0;
}