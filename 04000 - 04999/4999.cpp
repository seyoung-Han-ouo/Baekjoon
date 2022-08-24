#include <iostream>
using namespace std;

int main() {
	string jaehwan, doctor;

	cin >> jaehwan; // 재환이가 가장 길게 낼 수 있는 "aaah"
	cin >> doctor; // 의사가 듣기를 원하는 "aah"

	// 출력
	if (jaehwan.length() >= doctor.length())
		printf("go\n");
	else
		printf("no\n");
	
	return 0;
}