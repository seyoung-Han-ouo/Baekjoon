#include <iostream>
using namespace std;

int main() {
	int N, M, K; // 관중석의 크기 N과 M, 잃어버린 관중석 번호 K
	cin >> N >> M >> K;

	// 출력
	printf("%d %d\n", K / M, K % M);

	return 0;
}