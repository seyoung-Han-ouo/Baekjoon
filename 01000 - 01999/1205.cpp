#include <iostream>
using namespace std;

int N, ns, P;
int arr[51] = { -1 };

// 태수의 새로운 점수의 랭킹구하기
int findRanking() {
	int high = 0;
	int same = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (ns < arr[i]) high++;
		if (ns == arr[i]) same++;
	}

	printf("%d %d\n", high, same);

	if (same + high >= P) return -1;
	return high + 1;
}

int main() {
	scanf("%d %d %d", &N, &ns, &P);

	printf("%d\n", findRanking());

	return 0;
}