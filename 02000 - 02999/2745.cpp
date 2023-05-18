#include <iostream>
#include <cmath>
using namespace std;

int main() {
	string N; // B진법 수 
	int B; // B진법
	cin >> N >> B;

	int result = 0; // 10진법으로 변환한 결과
	int j = 0;

	for (int i = N.length() - 1; i >= 0; i--) {
		int num;

		// N의 각 자릿수를 int로
		if (N[i] >= 'A' && N[i] <= 'z')
			num = N[i] - 'A' + 10;
		else
			num = N[i] - '0';

		result += (num * pow(B, j++));
	}

	printf("%d\n", result);

	return 0;
}