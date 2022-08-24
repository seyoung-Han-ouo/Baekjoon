#include <iostream>
using namespace std;

int main() {
	// 전체 사람의 수 N
	int N;
	cin >> N;

	// 각 사람의 몸무게 x와 키 y
	int* x = new int[N]; 
	int* y = new int[N];

	for (int i = 0; i < N; i++)
		cin >> x[i] >> y[i];

	// i보다 큰 사람의 수를 계산한다.
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