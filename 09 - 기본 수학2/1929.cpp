#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int M, N;
	cin >> M >> N;

	// M부터 N 혹은 N까지의 숫자 중에서 소수를 찾는다.
	for (int i = M; i <= N; i++) {
		if (i == 2 || i == 3) 
			printf("%d\n", i);
		// 짝수는 소수가 될 수 없다.
		if (i % 2 == 0) continue;

		int num = sqrt(i);
		for (int j = 2; j <= num; j++) {
			// 소수는 자기자신과 1만으로만 나누어 떨어져야한다.
			if (i % j == 0) break;
			// 소수를 찾으면 출력
			if (j == num)
				printf("%d\n", i);
		}
	}

	return 0;
}