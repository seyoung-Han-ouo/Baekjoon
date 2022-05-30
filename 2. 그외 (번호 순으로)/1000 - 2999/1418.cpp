#include <iostream>
using namespace std;

int arr[100001] = { 0, 1 };

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= i; j++) {
				if (j == i) { // 소수일때
					// 소수의 배수에 해당 소수를 입력
					for (int k = i; k <= N; k += i)
						arr[k] = max(arr[k], i);
				}
				if (i % j == 0) break; // 소수가 아닐때
			}
		}
	}

	// K-세준수 세아리기
	int num = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= K) num++;
	}

	// 출력
	cout << num << endl;

	return 0;
}