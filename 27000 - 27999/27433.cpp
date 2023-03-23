#include <iostream>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);

	long long fact = 1;

	for (int i = 1; i <= N; i++) fact *= i;

	cout << fact << "\n";

	return 0;
}