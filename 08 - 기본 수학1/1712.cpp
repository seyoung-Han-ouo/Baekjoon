#include<iostream>
using namespace std;

int main() {
	int A, B, C; // �������, ���� ���, �ǸŰ���

	cin >> A >> B >> C;

	if (B >= C) 
		cout << -1; // B�� C���� ���ų� ũ�� ������ ������ �߻����� ����
	else
		cout << A / (C - B) + 1;
}