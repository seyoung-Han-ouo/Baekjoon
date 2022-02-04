#include <iostream>
using namespace std;

int main() {
	int T; // 테스트 케이스
	double x1, y1, r1; // 조규현의 좌표 (x1, y1), 조규현이 계산한 류재명과의 거리
	double x2, y2, r2; // 백승환의 좌표 (x2, y2), 백승환이 계산한 류재명과의 거리

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		// 두 터렛 사이의 거리
		double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);

		// 류재명이 있을 수 있는 좌표의 수 무한
		if(x1 == x2 && y1 == y2 && r1 == r2)
			cout << -1 << '\n';
		// 류재명이 있을 수 있는 좌표의 수 2
		else if (d > (r1 - r2) * (r1 - r2) && d < (r1 + r2) * (r1 + r2))
			cout << 2 << '\n';
		// 류재명이 있을 수 있는 좌표의 수 1
		else if (d == (r1 - r2) * (r1 - r2) || d == (r1 + r2) * (r1 + r2))
			cout << 1 << '\n';
		// 류재명이 있을 수 있는 좌표의 수 0
		else 
			cout << 0 << '\n';
	}
	
	return 0;
}