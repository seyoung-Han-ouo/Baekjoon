#include <iostream>
using namespace std;

int main() {
	int count; // N의 진짜 약수의 개수
	cin >> count;

	int small = 1000000; // 약수 중 가장 작은 수
	int big = 2; // 약수 중 가장 큰 수

	for (int i = 0; i < count; i++) {
		int divisor; // N의 진짜 약수
		scanf("%d", &divisor);

		// 가장 큰 수 찾기
		if (divisor > big)
			big = divisor;

		// 가장 작은 수 찾기
		if (divisor < small)
			small = divisor;
	}

	// 출력
	cout << big * small << endl;

	return 0;
}