#include <iostream>
using namespace std;

int arr[101];

// ������ �� �� ���ҽ�Ű�� �Ǵ��� ã��
int levelScore(int N) {
	int result = 0;

	for (int i = N - 2; i >= 0; i--) {
		if (arr[i] >= arr[i + 1]) { // ������ ���ҽ��Ѿ� �ϴ� �κ�
			result += (arr[i] - (arr[i + 1] - 1));
			arr[i] = (arr[i + 1] - 1);
		}
	}

	return result;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	printf("%d\n", levelScore(N));

	return 0;
}