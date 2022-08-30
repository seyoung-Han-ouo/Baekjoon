#include <iostream>
using namespace std;

int main() {
	int a[3]; // 케이크 수 a를 구성하는 자연수
	int c[3]; // 케이크 수 c를 구성하는 자연수

	for (int i = 0; i < 3; i++)
		cin >> a[i];

	for (int i = 0; i < 3; i++)
		cin >> c[i];

	printf("%d %d %d\n", c[0] - a[2], c[1] / a[1], c[2] - a[0]);

	return 0;
}