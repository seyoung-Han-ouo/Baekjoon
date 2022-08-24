#include <iostream>
using namespace std;

// 출발/도착점이 해당 행성계 안에 있는지 여부
bool contain(int x, int y, int cx, int cy, int r) {
	return ((x - cx) * (x - cx) + (y - cy) * (y - cy) < r * r);
}

int main() {
	int T; // 테스트 케이스의 개수
	cin >> T;

	for (int i = 0; i < T; i++) {
		int x1, y1; // 출발점 (x1, y1)
		int x2, y2; // 도착점 (x2, y2)

		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		int n; // 행성계의 개수 n
		cin >> n;

		int count = 0; // 지나야하는 행성계 수

		for (int j = 0; j < n; j++) {
			int cx, cy, r; // 행성계의 중점과 반지름 (cx, cy, r)

			scanf("%d %d %d", &cx, &cy, &r);

			bool start = contain(x1, y1, cx, cy, r);
			bool arrive = contain(x2, y2, cx, cy, r);

			if (start && arrive) // 출발/도착점이 모두 같은 행성계에 포함될 때
				continue;
			else if (start || arrive) // 출발/도착점 중 하나만 행성계에 포함될 때
				count++;
		}

		// 출력
		cout << count << "\n";
	}

	return 0;
}