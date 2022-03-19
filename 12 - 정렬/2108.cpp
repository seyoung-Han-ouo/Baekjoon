#include <iostream>
#include <cmath>
using namespace std;

// �迭
int arr[8001] = { 0 };

int main() {
	// ���� ���� N
	int N;
	cin >> N;

	int sum = 0;
	// �Է�
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;

		// �Է��� ���ڵ��� ��
		sum += c;

		// arr[4000]������ 0�� ������ ����
		if (c <= 0)
			arr[c + 4000]++;
		else
			arr[4001 + c]++;
	}

	int count = 0, mid;
	int lot[2];
	int lotNum = 0;
	int big = -4000, small = 4000;
	bool isFindMid = false;

	for (int i = 0; i < 8002; i++) {
		if (arr[i] != 0) {
			// i�� �Է��� ���ڷ� �ǵ�����
			int num = i;

			if (num < 4001)
				num -= 4000;
			else
				num -= 4001;

			// �߾Ӱ� ã��
			if (count + arr[i] >= N / 2 + 1 && !isFindMid) {
				mid = num;
				isFindMid = true;
			}
			else
				count += arr[i];

			// �ֺ� ã��
			// �� ���� ���� ���� ã���� ��
			if (arr[i] > lotNum) {
				lot[0] = num;
				lot[1] = num;
				lotNum = arr[i];
			}
			// ������ �ֺ󰪰� ���� Ƚ���� ���� ���϶�
			else if (arr[i] == lotNum) {
				// num�� lot[0]���� ���� ��
				if (num < lot[0]) {
					int c = lot[0];
					lot[0] = num;
					lot[1] = c;
				}
				// num�� lot[1]���� �۰ų� lot�� �� ���� ���� ���� ��
				else if (num < lot[1] || lot[0] == lot[1])
					lot[1] = num;
			}

			// �ּڰ� ã��
			if (num < small)
				small = num;

			// �ִ� ã��
			if (num > big)
				big = num;
		}
	}

	// ������ ���
	printf("%d\n", (int)round(sum / (double)N));

	printf("%d\n", mid);

	// �ֺ� ���
	printf("%d\n", lot[1]);

	// ���� ���
	printf("%d\n", big - small);

	return 0;
}