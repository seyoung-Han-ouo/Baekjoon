#include <iostream>
using namespace std;

int main() {
	// �Ǻ��� �� N, ������ ���� Q
	int N, Q;
	cin >> N >> Q;

	// �� �Ǻ��� ������ �ð�
	int* time = new int[N];

	// �� �Ǻ��� ������ �ð����ϱ�
	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);

		if (i == 0)
			time[i] = n - 1;
		else
			time[i] = time[i - 1] + n;
	}

	// �ش� �ð��� �θ��� �Ǻ� ��ȣ ã��
	for (int i = 0; i < Q; i++) {
		int q;
		scanf("%d", &q);

		for (int j = 0; j < N; j++) {
			if (q <= time[j]) {
				printf("%d\n", j + 1);
				break;
			}
		}
	}

	return 0;
}