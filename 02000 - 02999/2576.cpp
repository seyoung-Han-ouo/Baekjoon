#include <iostream>
using namespace std;

int main() {
	int sum = 0;
	int small = 100;

	for (int i = 0; i < 7; i++) {
		int n;
		scanf("%d", &n);

		if (n % 2 == 1) {
			sum += n;

			if (n < small) small = n;
		}
	}

	if (sum == 0) 
		printf("-1\n");
	else
		printf("%d\n%d", sum, small);

	return 0;
}