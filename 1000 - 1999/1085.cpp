#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int x, y; // 한수의 위치
	int w, h; // 직사각형의 오른쪽 위 꼭짓점

	cin >> x >> y >> w >> h;
	
	// 직사각형의 경제선부터 한수의 위치까지의 가로 거리
	int xDis = abs(w - x); 
	if (xDis > x)
		xDis = x; // (0, 0)부터 x까지의 거리

	// 직사각형의 경제선부터 한수의 위치까지의 세로 거리
	int yDis = abs(h - y); 
	if (yDis > y) 
		yDis = y; // (0, 0)부터 y까지의 거리

	// xDis와 yDis 중 더 작은 것을 출력
	int shortDis = (xDis <= yDis) ? xDis : yDis;
	cout << shortDis << '\n';

	return 0;
}