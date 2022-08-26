#include <iostream>
using namespace std;

int main() {
	int L; // 성우의 현재 위치와 민건이의 집까지의 거리
	cin >> L;

	// 민건이를 찾는 최소 시간
	int time = L / 5 + ((L % 5 == 0) ? 0 : 1);

	printf("%d\n", time);

	return 0;
}