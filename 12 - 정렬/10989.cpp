#include <iostream>
using namespace std;

// �迭
int arr[10001] = { 0 };

int main() {
	// ���� ���� N
	int N;
	scanf("%d", &N);

	// �Է�
	for (int i = 0; i < N; i++) {
		int c;
		scanf("%d", &c);

		arr[c]++;
	}

	// ���
	for (int i = 0; i < 10001; i++) {
		if (arr[i] != 0) {
			for (int j = 0; j < arr[i]; j++)
				printf("%d\n", i);
		}
	}

	return 0;
}