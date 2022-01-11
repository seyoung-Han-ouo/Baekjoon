#include <iostream>
using namespace std;

int main() {
	// 테스트 데이터 수, 호텔의 층 수, 각 층의 방 수, 몇 번째 손님
	int T, H, W, N;

	cin >> T;
	for (int i = 0; i < T; i++) {
		// 데이터 값 받기
		cin >> H >> W >> N;

		int YY = N % H;
		int XX = N / H + 1;

		if (YY == 0) {
			YY = H;
			XX = N / H;
		}

		cout << YY * 100 + XX << '\n';
	}
	
	return 0;
}