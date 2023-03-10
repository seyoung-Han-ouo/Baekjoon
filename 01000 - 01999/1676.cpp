#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	int count = 0; // 0의 개수
	
	for (int i = 5; i <= N; i *= 5)
		count += (N / i);

	// 0의 개수를 출력
	printf("%d\n", count);

	return 0;
}