#include <iostream>
using namespace std;

int main() {
	int piece[6] = { 1, 1, 2, 2, 2, 8 }; // 원래 있어야 하는 피스의 수
	int now[6]; // 지금 가지고 있는 피스의 수

	// 입력
	for (int i = 0; i < 6; i++)
		cin >> now[i];

	// 출력
	for (int i = 0; i < 6; i++)
		cout << piece[i] - now[i] << " ";
	
	return 0;
}