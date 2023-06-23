#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[300001];

int main() {
	int n;
	scanf("%d", &n);

	int dontSum = round((double)n * 0.15);
	double sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);

		sum += arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < dontSum; i++) {
		sum -= arr[i];
		sum -= arr[n - 1 - i];
	}

	if (n == 0) 
		cout << "0\n";
	else
		cout << round(sum / (n - dontSum * 2)) << "\n";

	return 0;
}