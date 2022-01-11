#include<iostream>
using namespace std;

// 1/1
// 1/2, 2/1
// 3/1, 2/2, 1/3
// 1/4, 2/3, 3/2, 4/1
// 홀수 번째의 분자는 1씩 증가하고, 분모는 1씩 감소한다.
// 짝수 번째의 분모는 1씩 증가하고, 분자는 1씩 감소한다.
int main() {
	int X, num = 0;
	cin >> X;

	for (int i = 1; ; i++) {
		num += i;
		if (num >= X) {
			// 짝수 번째
			if (i % 2 == 0)
				cout << i - (num - X) << "/" << 1 + (num - X);
			// 홀수 번째
			else
				cout << 1 + (num - X) << "/" << i - (num - X);
			break;
		}
	}

	return 0;
}