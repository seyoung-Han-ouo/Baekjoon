#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];

bool compare(int a, int b);
int sale(int N, int s);

bool compare(int a, int b) {
	return a > b;
}

// 할인 받아 무료로 지불하는 것들의 가격 빼기
int sale(int N, int s) {
	int sum = s;

	for (int i = 2; i < N; i += 3)
		sum -= arr[i];

	return sum;
}

int main() {
	int N, sum = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	sort(arr, arr + N, compare);

	printf("%d\n", sale(N, sum));

	return 0;
}