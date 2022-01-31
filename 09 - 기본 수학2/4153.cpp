#include <iostream>
using namespace std;

int main() {
	int a, b, c; // 테스트케이스, 양의 정수이다.

	while (true) {
		cin >> a >> b >> c;
		
		if (a + b + c == 0) break;

		// 각 변의 제곱
		int aa = a * a;
		int bb = b * b;
		int cc = c * c;

		// 가장 긴 변의 제곱이 나머지 변들의 합과 같으면 직각삼각형이다.
		if (aa + bb == cc || aa + cc == bb || bb + cc == aa)
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}
	
	return 0;
}