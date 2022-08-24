#include <iostream>
using namespace std;

int main() {
	string S; // 문자열 S
	cin >> S;

	// 각 알파벳에 해당하는 숫자를 누를 때 걸리는 시간을 배열에 저장
	int alpha[26] = { 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 8, 9, 9, 9, 10, 10, 10, 10 };

	// 전화를 걸기 위해서 걸리는 시간
	int time = 0;
	for (int i = 0; i < S.length(); i++)
		time += alpha[(int)S[i] - 'A'];

	// 출력
	cout << time;

	return 0;
}