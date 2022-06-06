#include <iostream>
using namespace std;

int main() {
	int A, B; // 시작 A, 끝 B
	cin >> A >> B;

	int num = 1; // 수열의 숫자
	int sum = 0; // 숫자의 합

	// A번째 숫자부터 B번째 숫자까지 합 구하기
	for (int i = 1; i <= B; ) {
		for (int j = 1; j <= num; j++) {
			if (i > B) break;

			if (i >= A) sum += num;

			i++;
		}
		num++;
	}

	// 출력
	cout << sum << endl;

	return 0;
}