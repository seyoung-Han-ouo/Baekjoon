#include <iostream>
using namespace std;

int main() {
	int L; // ������ ���� ��ġ�� �ΰ����� �������� �Ÿ�
	cin >> L;

	// �ΰ��̸� ã�� �ּ� �ð�
	int time = L / 5 + ((L % 5 == 0) ? 0 : 1);

	printf("%d\n", time);

	return 0;
}