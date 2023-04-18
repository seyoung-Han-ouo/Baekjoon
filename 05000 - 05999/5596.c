#include <stdio.h>

// 총점구하기
int sum() {
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int n;
		scanf("%d", &n);

		sum += n;
	}

	return sum;
}

int main() {
	int sum1 = sum(); // 민국이의 점수
	int sum2 = sum(); // 만세의 점수

	if (sum1 < sum2) sum1 = sum2;

	printf("%d\n", sum1);

	return 0;
}