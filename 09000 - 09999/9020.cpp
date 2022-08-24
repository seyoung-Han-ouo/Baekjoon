#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void Goldbach(vector<int> sosu, int n);

void Goldbach(vector<int> sosu, int n) {
	bool isFind = false;
	// n을 그 합으로 나타낼 수 있는 두 소수 찾기
	for (int j = 0; j < sosu.size(); j++) {
		if (isFind) break;

		for (int k = j; k >= 0; k--) {
			if (sosu[j] + sosu[k] == n) {
				// 출력
				printf("%d %d\n", sosu[k], sosu[j]);

				isFind = true;
				break;
			}
		}
	}
}

int main() {
	int T, n;
	vector<int> sosu;

	// 2부터 10000까지의 숫자 중에서 소수를 찾는다.
	for (int i = 2; i <= 10000; i++) {
		if (i == 2 || i == 3)
			sosu.push_back(i);

		// 짝수는 소수가 될 수 없다.
		if (i % 2 == 0) continue;

		int num = sqrt(i);
		for (int j = 2; j <= num; j++) {
			// 소수는 자기자신과 1로만 나누어 떨어져야한다.
			if (i % j == 0) break;
			// 소수를 찾으면 배열에 추가한다.
			if (j == num)
				sosu.push_back(i);
		}
	}

	// 테스트 케이스 T 입력
	cin >> T;
	for(int i = 0; i < T; i++) {
		cin >> n;

		Goldbach(sosu, n);
	}

	return 0;
}