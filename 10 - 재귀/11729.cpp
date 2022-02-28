#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int N, int j1, int j2, int j3) {
	if (N == 1)
		cout << j1 << " " << j3 << "\n";
	else {
		hanoi(N - 1, j1, j3, j2);
		cout << j1 << " " << j3 << "\n";
		hanoi(N - 1, j2, j1, j3);
	}
}

int main() {
	int N;
	cin >> N;

	cout << (int)pow(2, N) - 1 << '\n';
	hanoi(N, 1, 2, 3);
	
	return 0;
}