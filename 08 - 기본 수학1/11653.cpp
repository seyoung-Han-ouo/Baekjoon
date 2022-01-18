#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N, num;
	cin >> N;

	// N이 10보다 같거나 크면 제곱근을 구한다.
	if (N < 10) 
		num = N;
	else
		num = sqrt(N);

	// 2부터 N 혹은 N의 제곱근까지의 숫자 중에서 소수를 찾는다.
	for (int i = 2; i <= num; i++) {
		for (int j = 2; j <= i; j++) {
			// 소수를 찾으면 출력
			if (j == i) {	
				while (N % i == 0) {
					N /= i;
					printf("%d\n", i);
				}
			}
			else if (i % j == 0) break; // 소수는 자기자신과 1만으로만 나누어 떨어져야한다.
		}
	}

	if(N != 1)
		printf("%d\n", N);

	return 0;
}