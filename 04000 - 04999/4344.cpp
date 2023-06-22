#include <iostream>
#include <cmath>
using namespace std;

int arr[1001];

double sum(int N);

double sum(int N) {
	double sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		sum += arr[i];
	}

	return sum /= N;
}

int main() {
	int C; // 테스트 케이스의 개수
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		int N; // 학생의 수
		scanf("%d", &N);

		double ave = sum(N); // 평균
		int cnt = 0;

		// 평균을 넘는 학생들의 수 구하기
		for (int j = 0; j < N; j++)
			if (arr[j] > ave) cnt++;

		// 출력
		printf("%0.3lf%\n", round((cnt / (double)N) * 100000) / 1000);
	}
}