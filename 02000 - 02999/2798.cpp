#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	// 카드의 개수 N, 맞춰야하는 수 M
	int N, M;
	cin >> N >> M;

	// 카드에 적힌 숫자
	int* card = new int[N];
	for (int i = 0; i < N; i++)
		cin >> card[i];

	int sum = -1; //  카드의 합
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				// M을 넘지 않으면서 M에 최대한 가까운 카드 3장의 합을 찾는다.
				int add = card[i] + card[j] + card[k];

				if (sum == -1)
					sum = add;
				else if(abs(M - add) < abs(M - sum) && add <= M)
					sum = add;

				// sum이 M과 같으면 반복문 진행 불필요
				if (sum == M) break;
			}
			if (sum == M) break;
		}
		if (sum == M) break;
	}

	cout << sum;

	return 0;
}