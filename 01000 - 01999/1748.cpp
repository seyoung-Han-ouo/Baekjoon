#include <iostream>
using namespace std;

int countLen(int N);

// 자릿수 구하기
int countLen(int N) {
	int len = 0; // 자릿수
	int cnt = 1; // 각 숫자의 자릿수
	int useNum = 0; // 자릿수를 센 숫자의 개수

	for (int i = 10; i <= N; i *= 10) {
		int n = i - (i / 10);

		len += n * cnt++;
		useNum += n;
	}

	if (useNum != N)
		len += (N - useNum) * cnt;

	return len;
}

int main() {
	int N;
	scanf("%d", &N);

	printf("%d\n", countLen(N));

	return 0;
}