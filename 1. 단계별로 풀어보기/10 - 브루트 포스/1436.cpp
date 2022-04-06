#include <iostream>
using namespace std;

int main() {
	// N번째 영화의 제목
	int N;
	cin >> N;

	if (N <= 6)
		cout << (N - 1) * 1000 + 666;
	else {
		// 시간을 줄이기 위해 i를 6660으로 설정
		// count는 6이 3번 연속 나오는 숫자가 몇번째인지를 저장
		int i, count = 6;
		for (i = 6660; count < N; i++) {
			// i에 6이 3번 연속 나오는지 확인
			int j = i, is6 = 0;
			while (j > 0) {
				if (is6 == 3)
					break;
				else if (j % 10 == 6)
					is6++;
				else
					is6 = 0;

				j /= 10;
			}

			if (is6 == 3)
				count++;

			if (count == N)
				cout << i;
		}
	}

	return 0;
}