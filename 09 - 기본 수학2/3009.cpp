#include <iostream>
using namespace std;

void findSolo(int* oneTwo, int third);

// 세 점 중 혼자 좌표가 다른 것을 찾는다.
void findSolo (int* oneTwo, int third) {
	int solo;

	if (oneTwo[0] == oneTwo[1]) // 첫번째와 두번째 점의 좌표가 같음
		solo = third;
	else if (third == oneTwo[0]) // 첫번째와 세번째가 같음
		solo = oneTwo[1];
	else // 두번째와 세번째가 같음
		solo = oneTwo[0];

	cout << solo << " ";
}

int main() {
	// 점 2개의 위치 정보를 배열에 저장한다.
	int xNum[2], yNum[2];
	for (int i = 0; i < 2; i++)
		cin >> xNum[i] >> yNum[i];

	// 나머지 점 1개의 위치 정보
	int x, y;
	cin >> x >> y;

	findSolo(xNum, x);
	findSolo(yNum, y);
	
	return 0;
}