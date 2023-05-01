#include <iostream>
using namespace std;

int main() {
	int A, B, C, D;
	scanf("%d %d", &A, &B);
	scanf("%d %d", &C, &D);

	int min = A + D < B + C ? A + D : B + C;
	printf("%d\n", min);

	return 0;
}