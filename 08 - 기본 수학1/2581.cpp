#include <iostream>
using namespace std;

int main() {
	int N, M;
	
	cin >> M;
	cin >> N;

	int  add = 0, small = N;

	// M���� N������ ���� �߿��� �Ҽ��� ã�´�.
	for (int i = M; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			if (j == i) {
				add += i;
				if (i < small) small = i;
			}
			if (i % j == 0) break; // �Ҽ��� �ڱ��ڽŰ� 1�����θ� ������ ���������Ѵ�.
		}
	}

	// ���
	if (add == 0) cout << -1;
	else {
		cout << add << '\n' << small;
	}

	return 0;
}