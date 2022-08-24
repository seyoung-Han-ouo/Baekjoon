#include <iostream>
using namespace std;

int main() {
	int sum = 0; // ÃÑÁ¡

	for (int i = 0; i < 5; i++) {
		int n;
		cin >> n;

		sum += n;
	}

	// Ãâ·Â
	printf("%d", sum);
	
	return 0;
}