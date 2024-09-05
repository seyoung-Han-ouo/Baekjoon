#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int N;
long long sum = 3000000001;
long long arr[5001], result[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];

	sort(arr, arr + N);

	for (int i = 0; i < N - 2; i++) {
		int left = i + 1;
		int right = N - 1;

		while (left < right) {
			long long now = arr[i] + arr[left] + arr[right];

			if (abs(now) < abs(sum)) {
				sum = now;

				result[0] = arr[i];
				result[1] = arr[left];
				result[2] = arr[right];
			}

			if (now < 0) left++;
			else right--;
		}
	}

	for (int i = 0; i < 3; i++) cout << result[i] << ' ';
	cout << '\n';

	return 0;
}