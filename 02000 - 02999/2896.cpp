#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	double A, B, C, a, b, c;
	cin >> A >> B >> C >> a >> b >> c;

	double cnt = min(A / a, min(B / b, C / c));

	cout.precision(7);
	cout << A - (a * cnt) << ' ' << B - (b * cnt) << ' ' << C - (c * cnt) << '\n';

	return 0;
}