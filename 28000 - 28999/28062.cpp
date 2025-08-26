#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> holsu;

int holsuSum();

int holsuSum() {
	int cnt = 0;

	for (int i = (holsu.size() % 2 == 1); i < holsu.size(); i++) cnt += holsu[i];

	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, cnt = 0;
	cin >> N;

	while (N--) {
		int n;
		cin >> n;

		if (n % 2 == 0) cnt += n;
		else holsu.push_back(n);
	}

	sort(holsu.begin(), holsu.end());

	cout << cnt + holsuSum() << '\n';

	return 0;
}