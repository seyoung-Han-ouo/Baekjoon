#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M; // ������ ��
	cin >> M;

	int x, bit = 0;

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		switch (s[1])
		{
		case 'd': // S�� x�� �߰��Ѵ�.
			cin >> x;

			bit |= (1 << x);
			break;

		case 'e': // S���� x�� �����Ѵ�.
			cin >> x;

			bit &= ~(1 << x);
			break;

		case 'h': // S�� x�� ������ 1��, ������ 0�� ����Ѵ�.
			cin >> x;

			if (bit & (1 << x))
				printf("1\n");
			else
				printf("0\n");
			break;

		case 'o': // S�� x�� ������ x�� �����ϰ�, ������ x�� �߰��Ѵ�.
			cin >> x;

			bit ^= (1 << x);
			break;

		case 'l': // S��{ 1, 2, ..., 20 } ���� �ٲ۴�.
			bit = (1 << 21) - 1;
			break;

		case 'm': // S�� ���������� �ٲ۴�.
			bit = 0;
			break;
		}
	}

	return 0;
}