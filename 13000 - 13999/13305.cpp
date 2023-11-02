#include <iostream>
using namespace std;

long long road[100000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, cost;
	cin >> N;

	for (int i = 0; i < N - 1; i++) cin >> road[i];
	cin >> cost;

	int lastCost = cost;
	long long result = road[0] * cost;

	for (int i = 1; i < N - 1; i++) {
		cin >> cost;
		if (lastCost > cost) lastCost = cost;

		result += (road[i] * lastCost);
	}

	cout << result << '\n';

	return 0;
}