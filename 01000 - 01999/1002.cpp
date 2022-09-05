#include <iostream>
using namespace std;

int main() {
	int T; // �׽�Ʈ ���̽�
	double x1, y1, r1; // �������� ��ǥ (x1, y1), �������� ����� ��������� �Ÿ�
	double x2, y2, r2; // ���ȯ�� ��ǥ (x2, y2), ���ȯ�� ����� ��������� �Ÿ�

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// �� �ͷ� ������ �Ÿ�
		double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		// ������� ���� �� �ִ� ��ǥ�� �� ����
		if(x1 == x2 && y1 == y2 && r1 == r2)
			cout << -1 << '\n';
		// ������� ���� �� �ִ� ��ǥ�� �� 2
		else if (d > (r1 - r2) * (r1 - r2) && d < (r1 + r2) * (r1 + r2))
			cout << 2 << '\n';
		// ������� ���� �� �ִ� ��ǥ�� �� 1
		else if (d == (r1 - r2) * (r1 - r2) || d == (r1 + r2) * (r1 + r2))
			cout << 1 << '\n';
		// ������� ���� �� �ִ� ��ǥ�� �� 0
		else 
			cout << 0 << '\n';
	}
	
	return 0;
}