#include <iostream>
using namespace std;

// 별과 공백을 규칙에 맞게 출력한다.
void printStar(int i, int N) {
	for (int j = 0; j < N; j++) {
		if (j <= i || j >= N - i - 1)
			printf("*");
		else
			printf(" ");
	}
	printf("\n");
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		printStar(i, N * 2);

	for (int i = N - 2; i >= 0; i--) 
		printStar(i, N * 2);

	return 0;
}