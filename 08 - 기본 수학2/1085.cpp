#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	int x, y; // �Ѽ��� ��ġ
	int w, h; // ���簢���� ������ �� ������

	cin >> x >> y >> w >> h;
	
	// ���簢���� ���������� �Ѽ��� ��ġ������ ���� �Ÿ�
	int xDis = abs(w - x); 
	if (xDis > x)
		xDis = x; // (0, 0)���� x������ �Ÿ�

	// ���簢���� ���������� �Ѽ��� ��ġ������ ���� �Ÿ�
	int yDis = abs(h - y); 
	if (yDis > y) 
		yDis = y; // (0, 0)���� y������ �Ÿ�

	// xDis�� yDis �� �� ���� ���� ���
	int shortDis = (xDis <= yDis) ? xDis : yDis;
	cout << shortDis << '\n';

	return 0;
}