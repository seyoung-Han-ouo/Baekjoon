#include <iostream>
using namespace std;

void star(int N, int i, int j);

// ����� ������ ��� ĭ�� ���� �׸��� �Լ�
void star(int N, int i, int j) {
	if (i / N % 3 == 1 && j / N % 3 == 1)
		cout << " ";
	else if (N / 3 == 0 || N / 3 == 2)
		cout << "*";
	else
		star(N / 3, i, j);
}

int main() {
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star(N, i, j);
		}
		cout << '\n';
	}
	
	return 0;
}