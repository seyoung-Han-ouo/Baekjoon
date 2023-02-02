#include <iostream>
using namespace std;

int main() {
	int N; // 돌의 개수
	cin >> N;

	// 출력
	if (N % 2 == 1)
		printf("SK\n");
	else
		printf("CY\n");

	return 0;
}