#include <iostream>
using namespace std;

int main() {
	int n, m; // ���� ���� n, m

	while (true) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		// ù ��° ���� �� ��° ������ ũ�� Yes��, �ƴϸ� No�� ���
		if (n > m)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	
	return 0;
}