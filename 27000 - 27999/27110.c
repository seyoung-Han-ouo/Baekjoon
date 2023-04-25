#include <stdio.h>

int main() {
	int arr[4];

	for (int i = 0; i < 4; i++)
		scanf("%d", &arr[i]);

	int sum = 0;

	for (int i = 1; i < 4; i++) {
		int n = (arr[0] < arr[i]) ? arr[0] : arr[i];

		sum += n;
	}

	printf("%d\n", sum);

	return 0;
}