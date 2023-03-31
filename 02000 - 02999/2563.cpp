#include <iostream>
using namespace std;

int black(int a, int b);

bool paper[100][100] = { false };

// 이번 색종이로 생긴 검은 영역의 넓이
int black(int a, int b) {
	int count = 0; // 검은 영역의 넓이

	for (int i = a; i < a + 10; i++) {
		for (int j = b; j < b + 10; j++) {
			if (!paper[i][j]) {
				paper[i][j] = true;
				count++;
			}
		}
	}

	return count;
}

int main() {
	int n; // 색종이의 수
	scanf("%d", &n);

	int blackNum = 0; // 색종이가 붙은 검은 영역의 넓이

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);

		blackNum += black(a, b);
	}

	printf("%d\n", blackNum);

	return 0;
}