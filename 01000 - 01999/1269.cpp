#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map <int, bool> m;

int main() {
	int A, B, n;
	scanf("%d %d", &A, &B);

	for (int i = 0; i < A; i++) {
		scanf("%d", &n);

		m.insert({ n, 0 });
	}

	int same = 0;

	for (int i = 0; i < B; i++) {
		scanf("%d", &n);

		// 해당 원소가 이미 존재하는지 체크
		if (m.count(n) != 0) same++;
	}

	printf("%d\n", A + B - (same * 2));

	return 0;
}