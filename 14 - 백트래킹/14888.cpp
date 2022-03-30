#include <iostream>
using namespace std;

// 차례대로 덧셈(+)의 개수, 뺄셈(-)의 개수, 곱셈(×)의 개수, 나눗셈(÷)
int ns[4]; // 사칙연산의 개수 
int num[11]; // n개의 숫자 저장

int N; // 수의 개수
int small = 1000000000; // 최솟값
int big = -1000000000; // 최댓값

// 최댓값, 최솟값 찾기
void calculation(int result, int indx) {
	if (indx == N) {
		if (result < small)
			small = result;
		if (result > big)
			big = result;
	}
	// 경우의 수 찾기
	else {
		for (int i = 0; i < 4; i++) {
			if (ns[i] > 0) {
				ns[i]--;

				if(i == 0)
					calculation(result + num[indx], indx + 1);
				else if (i == 1)
					calculation(result - num[indx], indx + 1);
				else if (i == 2)
					calculation(result * num[indx], indx + 1);
				else
					calculation(result / num[indx], indx + 1);

				ns[i]++;
			}
		}
	}
}

int main() {
	// 입력
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> ns[i];

	// 최댓값, 최솟값 찾기
	calculation(num[0], 1);

	// 출력
	printf("%d\n%d", big, small);

	return 0;
}