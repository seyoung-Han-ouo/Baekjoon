#include <iostream>
#include <cmath>
using namespace std;

int arr[1001];

double sum(int N);

double sum(int N) {
	double sum = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		sum += arr[i];
	}

	return sum /= N;
}

int main() {
	int C; // �׽�Ʈ ���̽��� ����
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		int N; // �л��� ��
		scanf("%d", &N);

		double ave = sum(N); // ���
		int cnt = 0;

		// ����� �Ѵ� �л����� �� ���ϱ�
		for (int j = 0; j < N; j++)
			if (arr[j] > ave) cnt++;

		// ���
		printf("%0.3lf%\n", round((cnt / (double)N) * 100000) / 1000);
	}
}