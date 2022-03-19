#include <iostream>
#include <cmath>
using namespace std;

// 배열
int arr[8001] = { 0 };

int main() {
	// 수의 개수 N
	int N;
	cin >> N;

	int sum = 0;
	// 입력
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;

		// 입력한 숫자들의 합
		sum += c;

		// arr[4000]까지는 0과 음수를 저장
		if (c <= 0)
			arr[c + 4000]++;
		else
			arr[4001 + c]++;
	}

	int count = 0, mid;
	int lot[2];
	int lotNum = 0;
	int big = -4000, small = 4000;
	bool isFindMid = false;

	for (int i = 0; i < 8002; i++) {
		if (arr[i] != 0) {
			// i를 입력한 숫자로 되돌리기
			int num = i;

			if (num < 4001)
				num -= 4000;
			else
				num -= 4001;

			// 중앙값 찾기
			if (count + arr[i] >= N / 2 + 1 && !isFindMid) {
				mid = num;
				isFindMid = true;
			}
			else
				count += arr[i];

			// 최빈값 찾기
			// 더 자주 나온 수를 찾았을 때
			if (arr[i] > lotNum) {
				lot[0] = num;
				lot[1] = num;
				lotNum = arr[i];
			}
			// 현재의 최빈값과 같은 횟수로 나온 수일때
			else if (arr[i] == lotNum) {
				// num이 lot[0]보다 작을 때
				if (num < lot[0]) {
					int c = lot[0];
					lot[0] = num;
					lot[1] = c;
				}
				// num이 lot[1]보다 작거나 lot의 두 수가 서로 같을 때
				else if (num < lot[1] || lot[0] == lot[1])
					lot[1] = num;
			}

			// 최솟값 찾기
			if (num < small)
				small = num;

			// 최댓값 찾기
			if (num > big)
				big = num;
		}
	}

	// 산술평균 출력
	printf("%d\n", (int)round(sum / (double)N));

	printf("%d\n", mid);

	// 최빈값 출력
	printf("%d\n", lot[1]);

	// 범위 출력
	printf("%d\n", big - small);

	return 0;
}