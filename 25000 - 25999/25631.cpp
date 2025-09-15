#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;
unordered_map<int, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		m[n]++;

		if (m[n] == 1) arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	int n = m[arr[0]];

	for (int i = 1; i < arr.size(); i++) {
		N -= min(n, m[arr[i]]);
		n -= min(n, m[arr[i]]);
		n += m[arr[i]];
	}

	cout << n << '\n';

	return 0;
}