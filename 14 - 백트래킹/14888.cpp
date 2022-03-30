#include <iostream>
using namespace std;

// ���ʴ�� ����(+)�� ����, ����(-)�� ����, ����(��)�� ����, ������(��)
int ns[4]; // ��Ģ������ ���� 
int num[11]; // n���� ���� ����

int N; // ���� ����
int small = 1000000000; // �ּڰ�
int big = -1000000000; // �ִ�

// �ִ�, �ּڰ� ã��
void calculation(int result, int indx) {
	if (indx == N) {
		if (result < small)
			small = result;
		if (result > big)
			big = result;
	}
	// ����� �� ã��
	else {
		for (int i = 0; i < 4; i++) {
			if (ns[i] > 0) {
				ns[i]--;

				if(i == 0)
					calculation(result + num[indx], indx + 1);
				else if (i == 1)
					calculation(result - num[indx], indx + 1);
				else if (i == 2)
					calculation(result * num[indx], indx + 1);
				else
					calculation(result / num[indx], indx + 1);

				ns[i]++;
			}
		}
	}
}

int main() {
	// �Է�
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = 0; i < 4; i++)
		cin >> ns[i];

	// �ִ�, �ּڰ� ã��
	calculation(num[0], 1);

	// ���
	printf("%d\n%d", big, small);

	return 0;
}