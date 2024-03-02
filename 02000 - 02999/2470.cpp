#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int mn, mx;
int arr[100000];

void binary(int low, int high);

void binary(int low, int high) {
	int result = 2000000001;

	while (low < high) {
		int sum = arr[low] + arr[high];

		if (abs(sum) < result) {
			result = abs(sum);
			mn = low;
			mx = high;
		}

		if (sum == 0) break;

		if (sum < 0) low++;
		else high--;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	binary(0, N - 1);

	cout << arr[mn] << ' ' << arr[mx] << '\n';

	return 0;
}