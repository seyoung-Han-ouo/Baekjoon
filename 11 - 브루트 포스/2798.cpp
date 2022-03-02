#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	// ī���� ���� N, ������ϴ� �� M
	int N, M;
	cin >> N >> M;

	// ī�忡 ���� ����
	int* card = new int[N];
	for (int i = 0; i < N; i++)
		cin >> card[i];

	int sum = -1; //  ī���� ��
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				// M�� ���� �����鼭 M�� �ִ��� ����� ī�� 3���� ���� ã�´�.
				int add = card[i] + card[j] + card[k];

				if (sum == -1)
					sum = add;
				else if(abs(M - add) < abs(M - sum) && add <= M)
					sum = add;

				// sum�� M�� ������ �ݺ��� ���� ���ʿ�
				if (sum == M) break;
			}
			if (sum == M) break;
		}
		if (sum == M) break;
	}

	cout << sum;

	return 0;
}