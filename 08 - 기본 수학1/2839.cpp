#include <iostream>
using namespace std;

int bag(int N);

int bag(int N) {
	int count = 0;
	int num = N;

	// 5kg 봉지만 들고 가는게 가장 적을때
	if (N % 5 == 0) return N / 5;
	
	// 5kg, 3kg 섞어서 들고 가는 경우
	num = N % 5;
	for (count = N / 5; count >= 0; count--) {
		if (num % 3 == 0) {
			count += num / 3;
			break;
		}
		num += 5;
	}

	// 3kg 봉지만 들고 가는게 가장 적을때
	if (count == -1 && N % 3 == 0)
		count = N / 3;

	return count;
}

int main() {
	int N;
	cin >> N;
	
	cout << bag(N);
	
	return 0;
}