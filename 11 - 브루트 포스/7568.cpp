#include <iostream>
using namespace std;

int main() {
	// ��ü ����� �� N
	int N;
	cin >> N;

	// �� ����� ������ x�� Ű y
	int* x = new int[N]; 
	int* y = new int[N];

	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	// i���� ū ����� ���� ����Ѵ�.
	for (int i = 0; i < N; i++) {
		int rank = 1;
		for (int j = 0; j < N; j++) {
			if (x[i] < x[j] && y[i] < y[j])
				rank++;
		}
		cout << rank << " ";
	}

	return 0;
}