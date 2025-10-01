#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, W;
	cin >> N >> W;

	int score = N * 10;

	if (N >= 3) score += 20;
	if (N == 5) score += 50;
	if (W > 1000) score -= 15;

	if (score < 0) cout << "0\n";
	else cout << score << '\n';

	return 0;
}