#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> x, y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	while (n--) {
		int a, b;
		cin >> a >> b;

		x[a]++;
		y[b]++;
	}

	int cnt = 0;
	for (const auto& pair : x)
		cnt += (pair.second >= 2);

	for (const auto& pair : y)
		cnt += (pair.second >= 2);

	cout << cnt << '\n';

	return 0;
}