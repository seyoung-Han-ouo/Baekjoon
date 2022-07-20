#include <iostream>
using namespace std;

// 조합
int combination(int M, int N) {
	long int num1 = 1; // 분자
	long int num2 = 1; // 분모

	for (int i = 0; i < N; i++) {
		num1 *= M--;
		num2 *= (i + 1);

		// int 범위를 넘어가는 것을 막기 위해 약분
		if (num1 % (i + 1) == 0 && num2 % (i + 1) == 0) {
			num1 /= (i + 1);
			num2 /= (i + 1);
		}
	}

	return num1 / num2;
}

int main() {
	int T; // 테스트 케이스의 개수 
	cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M; // 강의 서쪽과 동쪽에 있는 사이트의 개수 (N ≤ M)
		scanf("%d %d", &N, &M);

		// 출력
		cout << combination(M, N) << endl;
	}
	return 0;
}