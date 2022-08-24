#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// A :낮에 올라가는 거리, B : 미끄러지는 거리, V : 막대기의 높이
	double A, B, V;

	cin >> A >> B >> V;

	cout << (int)ceil((V - A) / (A - B)) + 1;

	return 0;
}