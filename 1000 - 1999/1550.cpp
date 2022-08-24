#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	string n; // 16진수 수
	cin >> n;

	reverse(n.begin(), n.end());

	int ten = 0; // 10진수

	// 16진수의 수를 10진수로 변환하기
	for (int i = 0; i < n.length(); i++) {
		if (i >= n.length()) break;

		int num = n[i] - '0';

		if (n[i] >= 'A')
			num = n[i] - 'A' + 10;

		ten += (num * pow(16, i));
	}

	// 출력
	cout << ten << endl;

	return 0;
}