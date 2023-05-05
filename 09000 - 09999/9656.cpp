#include <iostream>
using namespace std;

int main() {
	int N; // 돌 N개
	scanf("%d", &N);

	int turn = N / 3 + N % 3;

	// 상근이가 이기면 SK를, 창영이가 이기면 CY을 출력
	if (turn % 2 == 0)
		printf("SK\n");
	else
		printf("CY\n");

	return 0;
}