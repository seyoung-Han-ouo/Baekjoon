#include <iostream>
#include <vector>
using namespace std;

vector<int> arr;
bool check[1000001] = { false };

void findPrime();

void findPrime() {
	for (int i = 2; i <= 1000000; i++) {
		if (check[i]) continue;

		for (int j = i * 2; j <= 1000000; j += i) check[j] = true;
		arr.push_back(i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	findPrime();

	while (true) {
		int n;
		cin >> n;

		if (n == 0) break;

		for (int i = 0; i < arr.size(); i++) {
			if (check[(n - arr[i])] == false) {
				cout << n << " = " << arr[i] << " + " << n - arr[i] << '\n';
				break;
			}
		}
	}

	return 0;
}