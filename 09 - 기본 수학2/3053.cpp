#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double R; // 반지름

	cin >> R;

	// 5자리까지 소수점 자리 표시
	cout << fixed;
	cout.precision(6);

	// 유클리드 기하학에서 원의 넓이
	cout << R * R * acos(-1) << '\n';

	// 택시 기하학에서 원의 넓이
	cout << R * R * 2;
	
	return 0;
}