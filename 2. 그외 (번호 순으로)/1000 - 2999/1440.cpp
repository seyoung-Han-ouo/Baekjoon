#include <iostream>
#include <string>
using namespace std;

int main() {
	string d;
	cin >> d;

	int time[3];

	// 입력한 문자열에서 숫자 뽑아내기
	time[0] = stoi(d.substr(0, 2));
	time[1] = stoi(d.substr(3, 5));
	time[2] = stoi(d.substr(6));

	int canT = 0; // 시 자리에 들어갈 수 있는 숫자의 개수

	for (int i = 0; i < 3; i++) {
		if (time[i] > 59) { // 초나 분에도 들어가지 못하는 숫자가 있을 때
			canT = 0;
			break;
		}

		if (time[i] > 0 && time[i] <= 12) canT++;
	}

	// 출력
	cout << canT * 2 << endl;

	return 0;
}