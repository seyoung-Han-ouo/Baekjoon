#include <iostream>
using namespace std;

int main() {
	char sign[3] = {'+', '0', '-'}; // 성적의 부호
	double score[3] = { 4.3, 4.0, 3.7 }; // 각 부호의 최고 점수

	string c;
	cin >> c;

	double num = 0; // 평점

	// 평점 구하기
	if (c[0] != 'F') {
		int i;
		for (i = 0; i < 3; i++)
			if (sign[i] == c[1]) break;

		int n = c[0] - 'A';
		num = score[i] - n;
	}

	// 소수점 자리 고정
	cout << fixed;
	cout.precision(1);

	// 출력
	cout << num << endl;
	
	return 0;
}