#include <iostream>
#include <ctime>
using namespace std;

int main() {
	time_t timer = time(NULL); // 현재 시간
	struct tm* t = localtime(&timer);

	// 출력
	cout << t->tm_year + 1900 << "-";

	cout.width(2); // 글자 수 지정
	cout.fill('0'); // 빈 공간 0으로 채우기

	cout << t->tm_mon + 1 << "-" << t->tm_mday << endl;

	return 0;
}