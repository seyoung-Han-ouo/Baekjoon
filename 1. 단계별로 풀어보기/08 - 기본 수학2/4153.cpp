#include <iostream>
using namespace std;

int main() {
	int a, b, c; // �׽�Ʈ���̽�, ���� �����̴�.

	while (true) {
		cin >> a >> b >> c;
		
		if (a + b + c == 0) break;

		// �� ���� ����
		int aa = a * a;
		int bb = b * b;
		int cc = c * c;

		// ���� �� ���� ������ ������ ������ �հ� ������ �����ﰢ���̴�.
		if (aa + bb == cc || aa + cc == bb || bb + cc == aa)
			cout << "right" << "\n";
		else
			cout << "wrong" << "\n";
	}
	
	return 0;
}