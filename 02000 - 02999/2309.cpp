#include <iostream>
#include <algorithm>
using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sum = -100;
	int arr[9];

	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		sum += arr[i];
	}

	sort(arr, arr + 9);

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (arr[i] + arr[j] == sum) {
				for (int k = 0; k < 9; k++)
					if (k != i && k != j) cout << arr[k] << '\n';

				return 0;
			}
		}
	}
}