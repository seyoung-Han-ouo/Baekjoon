#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n = -1;

	while (true) {
		cin >> n;

		if (n == 0) break;

		int count = 0;
		// N + 1부터 2N까지의 숫자 중에서 소수를 찾는다.
		for (int i = n + 1; i <= n * 2; i++) {
			if (i == 2 || i == 3)
				count++;
			// 짝수는 소수가 될 수 없다.
			if (i % 2 == 0) continue;

			int num = sqrt(i);
			for (int j = 2; j <= num; j++) {
				// 소수는 자기자신과 1로만 나누어 떨어져야한다.
				if (i % j == 0) break;
				// 소수를 찾으면 count를 증가시킨다.
				if (j == num)
					count++;
			}
		}

		printf("%d\n", count);
	}

	return 0;
}