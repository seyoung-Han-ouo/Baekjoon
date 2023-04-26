#include <iostream>
#include <set>
using namespace std;

int findMax(int N);

set<int> rope; // 로프의 종류
int arr[10001] = { 0 }; // 각 로프의 개수

// 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량을 구하기
int findMax(int N) {
	int max = 0; // 최대 중량
	int noUse = 0; // 사용하지 않는 로프의 수

	for (set<int>::iterator iter = rope.begin(); iter != rope.end(); iter++) {
		int weight = (N - noUse) * (*iter);

		if (weight > max) max = weight;
		noUse += arr[*iter];
	}

	return max;
}

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		arr[num]++;
		rope.insert(num);
	}

	printf("%d\n", findMax(N));

	return 0;
}