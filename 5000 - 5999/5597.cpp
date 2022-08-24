#include <iostream>
using namespace std;

int main() {
	bool student[30] = {};

	for (int i = 0; i < 28; i++) {
		int n;
		cin >> n; // 입력

		student[n - 1] = true; // 제출한 학생 체크
	}

	// 출력
	for (int i = 0; i < 30; i++)
		if (!student[i]) printf("%d\n", i + 1);
	
	return 0;
}