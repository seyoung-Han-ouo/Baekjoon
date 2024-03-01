#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000];

int binary(int N, int find);

int binary(int N, int find) {
	int low = 0;
	int high = N - 1;

	while (low <= high) {
		int mid = (low + high) / 2;

		if (arr[mid] == find) return 1;

		if (arr[mid] < find) low = mid + 1; 
		else high = mid - 1;
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int T;
	cin >> T;

	while (T--) {
		int N, M;

		cin >> N;
		for (int i = 0; i < N; i++) cin >> arr[i];
		cin >> M;

		sort(arr, arr + N);

		for (int i = 0; i < M; i++) {
			int find;
			cin >> find;

			cout << binary(N, find) << '\n';
		}
	}

	return 0;
}