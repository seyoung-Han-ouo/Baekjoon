#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string n; // 2진수
	cin >> n;

	string num8 = ""; // 8진수

	// 진수 변환
	for (int i = n.length() - 1; i >= 0; ) {
		int sum = 0;

		// 2진수를 3개씩 쪼개서 진수 변환
		for (int j = 0; j < 3; j++) {
			if (i < 0) break;

			int num2 = n[i] - '0';

			sum += num2 * pow(2, j);
			i--;
		}

		// 변환한 수 합치기
		num8.append(to_string(sum));
	}

	// 문자열 뒤집기
	reverse(num8.begin(), num8.end());

	// 출력
	cout << num8 << endl;

	return 0;
}