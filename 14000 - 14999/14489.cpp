#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int money = (a + b) < c * 2 ? a + b : (a + b) - c * 2;
	printf("%d\n", money);

	return 0;
}