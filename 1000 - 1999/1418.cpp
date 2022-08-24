#include <iostream>
using namespace std;

int arr[100001] = { 0, 1 };

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; i++) {
		if (arr[i] == 0) {
			for (int j = 2; j <= i; j++) {
				if (j == i) { // �Ҽ��϶�
					// �Ҽ��� ����� �ش� �Ҽ��� �Է�
					for (int k = i; k <= N; k += i)
						arr[k] = max(arr[k], i);
				}
				if (i % j == 0) break; // �Ҽ��� �ƴҶ�
			}
		}
	}

	// K-���ؼ� ���Ƹ���
	int num = 0;
	for (int i = 1; i <= N; i++) {
		if (arr[i] <= K) num++;
	}

	// ���
	cout << num << endl;

	return 0;
}