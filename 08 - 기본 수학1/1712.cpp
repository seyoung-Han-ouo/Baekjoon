#include<iostream>
using namespace std;

int main() {
	int A, B, C; // 고정비용, 가변 비용, 판매가격

	cin >> A >> B >> C;

	if (B >= C) 
		cout << -1; // B가 C보다 같거나 크면 영원히 이익이 발생하지 않음
	else
		cout << A / (C - B) + 1;
}