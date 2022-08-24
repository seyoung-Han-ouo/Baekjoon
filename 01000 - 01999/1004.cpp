#include <iostream>
using namespace std;

// ���/�������� �ش� �༺�� �ȿ� �ִ��� ����
bool contain(int x, int y, int cx, int cy, int r) {
	return ((x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r);
}

int main() {
	int T; // �׽�Ʈ ���̽��� ����
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1; // ����� (x1, y1)
		int x2, y2; // ������ (x2, y2)

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int n; // �༺���� ���� n
		cin >> n;

		int count = 0; // �������ϴ� �༺�� ��

		for (int j = 0; j < n; j++) {
			int cx, cy, r; // �༺���� ������ ������ (cx, cy, r)

			scanf("%d %d %d", &cx, &cy, &r);

			bool start = contain(x1, y1, cx, cy, r);
			bool arrive = contain(x2, y2, cx, cy, r);

			if (start && arrive) // ���/�������� ��� ���� �༺�迡 ���Ե� ��
				continue;
			else if (start || arrive) // ���/������ �� �ϳ��� �༺�迡 ���Ե� ��
				count++;
		}

		// ���
		cout << count << "\n";
	}

	return 0;
}