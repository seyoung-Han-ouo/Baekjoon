#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int zero, one;
vector<int> pl, mi;

bool compare(int a, int b);
int plusNum(int len);
int minusNum(int len);

// 내림차순
bool compare(int a, int b) {
	return a > b;
}

// 양수의 합
int plusNum(int len) {
	int sum = 0;
	int start = 1;

	// 개수가 홀수인 경우
	if (len % 2 == 1) {
		sum += pl[0];
		start++;
	}

	// 두 수를 묶어서 곱한 뒤 더하기
	for (int i = start; i < len; i += 2) 
		sum += (pl[i - 1] * pl[i]);

	return sum;
}

// 음수의 합
int minusNum(int len) {
	int sum = 0;
	int start = 1;

	// 개수가 홀수인 경우
	if (len % 2 == 1) {
		// 0으로 숫자를 없앨 수 없다면
		if (zero == 0) sum += mi[0];
		start++;
	}

	// 두 수를 묶어서 곱한 뒤 더하기
	for (int i = start; i < len; i += 2)
		sum += (mi[i - 1] * mi[i]);

	return sum;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n == 0) zero++;
		else if (n == 1) one++;
		else if (n < 0) mi.push_back(n);
		else pl.push_back(n);
	}

	sort(pl.begin(), pl.end());
	sort(mi.begin(), mi.end(), compare);

	cout << plusNum(pl.size()) + minusNum(mi.size()) + one << '\n';

	return 0;
}