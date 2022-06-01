#include <iostream>
using namespace std;

bool seat[101] = {};

int main() {
	int N; // 손님의 수 N
	cin >> N;

	int count = 0; // 거절당하는 사람의 수

	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);

		// 거절당하는 경우
		if (seat[num]) count++;
		
		seat[num] = true;
	}

	// 출력
	cout << count << endl;

	return 0;
}