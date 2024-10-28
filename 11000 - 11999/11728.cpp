#include <iostream>
using namespace std;

#define SIZE 1000000

int N, M;
int A[SIZE], B[SIZE];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < M; i++) cin >> B[i];

	int a = 0, b = 0;

	while (true) {
		if (a >= N || b >= M) break;

		if (A[a] < B[b]) cout << A[a++] << ' ';
		else cout << B[b++] << ' ';
	}

	for (int i = a; i < N; i++) cout << A[i] << ' ';
	for (int i = b; i < M; i++) cout << B[i] << ' ';

	return 0;
}