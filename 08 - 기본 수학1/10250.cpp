#include <iostream>
using namespace std;

int main() {
	// �׽�Ʈ ������ ��, ȣ���� �� ��, �� ���� �� ��, �� ��° �մ�
	int T, H, W, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		// ������ �� �ޱ�
		cin >> H >> W >> N;

		int YY = N % H;
		int XX = N / H + 1;

		if (YY == 0) {
			YY = H;
			XX = N / H;
		}

		cout << YY * 100 + XX << '\n';
	}
	
	return 0;
}