#include <iostream>
using namespace std;

int N; // ���� ����
int num[20][20]; // ���� ����
bool team[20] = { false };

int start[10];
int link[10];

int sum = 1000000000; // ����

// ��ŸƮ ���� ��ũ ���� �ɷ�ġ�� ������ �ּڰ� ã��
void Team(int inx, int cnt) {
	if (cnt == N / 2) {
		int result1 = 0;
		int result2 = 0;

		// ������ 2���� �迭�� ����
		int idx1 = 0, idx2 = 0;
		for (int i = 0; i < N; i++) {
			if (team[i])
				start[idx1++] = i;
			else
				link[idx2++] = i;
		}

		// ������ �ɷ�ġ ��
		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				result1 += num[start[i]][start[j]];
				result2 += num[link[i]][link[j]];
			}
		}

		// ���� �ɷ�ġ ���̰� �ּ������� Ȯ��
		if (abs(result1 - result2) < sum)
			sum = abs(result1 - result2);
	}
	// ���� ������ ����� �� ã��
	else {
		for (int i = inx; i < N; i++) {
			if (!team[i]) {
				team[i] = true;

				Team(i, cnt + 1);

				team[i] = false;
			}
		}
	}
}

int main() {
	// �Է�
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			scanf("%d", &num[i][j]);
	}

	// ��ŸƮ ���� ��ũ ���� �ɷ�ġ�� ������ �ּڰ� ã��
	Team(0, 0);

	// ���
	printf("%d", sum);

	return 0;
}