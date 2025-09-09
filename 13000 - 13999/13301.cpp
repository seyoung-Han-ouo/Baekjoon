#include <iostream>
using namespace std;

long long arr[81];

void init(int N);

void init(int N) {
	arr[0] = arr[1] = 1;

	for (int i = 2; i < N; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	init(N);

	cout << arr[N - 1] * 4 + arr[N - 2] * 2 << '\n';

	return 0;
}