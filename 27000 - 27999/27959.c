#include <stdio.h>

int main() {
	int N, M;
	scanf("%d %d", &N, &M);

	if (M > N * 100) 
		printf("No\n");
	else
		printf("Yes\n");

	return 0;
}
