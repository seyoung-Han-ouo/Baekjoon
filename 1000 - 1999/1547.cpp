#include <iostream>
using namespace std;

int main() {
	int M; // 컵의 위치를 바꾼 횟수
	cin >> M;

	int cup[3] = { 1, 2, 3 }; // 컵의 위치

	for (int i = 0; i < M; i++) {
		int X, Y; // 컵의 위치를 바꾼 방법 X, Y
		scanf("%d %d", &X, &Y);

		// 해당 번호를 가진 컵의 위치 찾기
		int idx1, idx2;
		for (int j = 0; j < 3; j++) {
			if (cup[j] == X) idx1 = j;
			if (cup[j] == Y) idx2 = j;
		}

		// 컵 위치 바꾸기
		cup[idx1] = Y;
		cup[idx2] = X;
	}

	// 출력
	cout << cup[0] << endl;

	return 0;
}