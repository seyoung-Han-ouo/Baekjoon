#include <iostream>
#include <algorithm>
using namespace std;

int N, M, arr[10000];

int binary();

int binary() {
	int low = 0;
	int high = arr[N - 1];
	int result = 0;

	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;

		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) 
				sum += mid;
			else
				sum += arr[i];
		}

		if (sum > M) high = mid - 1;
		else {
			result = max(result, mid);
			low = mid + 1;
		}
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> M;

	sort(arr, arr + N);

	cout << binary() << '\n';

	return 0;
}