#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int cnt = D + E;
	A -= min(A, D);

	cnt += C;
	if (B >= C) 
		B -= C;
	else {
		A -= (C - B) * 2;
		B = 0;
	}

	if (B > 0) {
		cnt += B / 2 + B % 2;
		A -= B / 2 + (B % 2) * 3;
	}

	if (A > 0) cnt += A / 5 + (bool)(A % 5);

	cout << cnt << '\n';

	return 0;
}