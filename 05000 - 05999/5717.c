#include <stdio.h>

int main() {
	while(1) {
		int m, f;
		scanf("%d %d", &m, &f);

		if (m == 0 && f == 0) break;

		printf("%d\n", m + f);
	}

	return 0;
}