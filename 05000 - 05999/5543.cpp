#include <iostream>
using namespace std;

int main() {
	int buger = 2000;
	int drink = 2000;

	for (int i = 0; i < 3; i++) {
		int n;
		scanf("%d", &n);

		if (n < buger) buger = n;
	}

	for (int i = 0; i < 2; i++) {
		int n;
		scanf("%d", &n);

		if (n < drink) drink = n;
	}

	printf("%d\n", buger + drink - 50);

	return 0;
}