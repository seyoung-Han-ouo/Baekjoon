#include <iostream>
#include <algorithm>
using namespace std;

int N, arr[2001];

int findSum(int left, int right, int idx);

int findSum(int left, int right, int idx) {
	while (left < right) {
		if (left == idx) {
			left++;
			continue;
		}
		if (right == idx) {
			right--;
			continue;
		}

		int sum = arr[left] + arr[right];

		if (sum == arr[idx]) return 1;

		if (sum < arr[idx]) left++;
		else right--;
	}
	
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	int cnt = 0;

	for (int i = 0; i < N; i++) {
		cnt += findSum(0, N - 1, i);
	}

	cout << cnt << '\n';

	return 0;
}