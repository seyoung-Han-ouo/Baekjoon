#include <stdio.h>

int main() {
	int arr[5];

	for (int i = 0; i < 5; i++)
		scanf("%d", &arr[i]);

	int n1 = arr[1] / arr[3];
	n1 = arr[1] % arr[3] == 0 ? n1 : n1 + 1;

	int n2 = arr[2] / arr[4];
	n2 = arr[2] % arr[4] == 0 ? n2 : n2 + 1;

	arr[0] = n1 > n2 ? arr[0] - n1 : arr[0] - n2;

	printf("%d\n", arr[0]);

	return 0;
}