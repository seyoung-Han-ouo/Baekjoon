#include <iostream>
#include <algorithm>
using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
int arr[100];

string chgString(int n);
bool compare(int a, int b);

// 숫자를 문자열로
string chgString(int n) {
	string s;

	if (n < 10)
		s = num[n];
	else
		s = num[n / 10] + " " + num[n % 10];

	return s;
}

// 정렬
bool compare(int a, int b) {
	string s1 = chgString(a);
	string s2 = chgString(b);

	return s1 < s2;
}

int main() {
	int M, N;
	scanf("%d %d", &M, &N);

	int idx = N - M + 1;

	for (int i = 0; i < idx; i++)
		arr[i] = M + i;

	sort(arr, arr + idx, compare);

	// 한 줄에 10개씩 출력
	for (int i = 0; i < idx; i++) {
		printf("%d ", arr[i]);

		if ((i + 1) % 10 == 0) printf("\n");
	}

	return 0;
}