#include <iostream>
using namespace std;

// 별과 공백을 규칙에 맞게 출력한다.
void printStar(int idx, int N) {
	for (int i = 0; i < idx; i++)
		printf(" ");

	for (int i = 0; i < N - (idx * 2); i++)
		printf("*");

	printf("\n");
}

int main() {
	int N;
	cin >> N;

	// 삼각형
	for (int i = 0; i < N; i++)
		printStar(i, N * 2 - 1);

	// 역삼각형
	for (int i = N - 2; i >= 0; i--) 
		printStar(i, N * 2 - 1);

	return 0;
}