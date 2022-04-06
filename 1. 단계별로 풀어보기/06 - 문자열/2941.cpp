#include <iostream>
#include <string>
using namespace std;

int main() {
	// 크로아티아 알파벳 S
	string S; 
	cin >> S;

	int count = 0;
	for (int i = 0; i < S.length(); i++) {
		if (S.substr(i, 3) == "dz=") {
			count++;
			i += 2;
		}
		else if (S[i + 1] == '-' || S[i + 1] == '=') {
			count++;
			i += 1;
		}
		else if (S.substr(i, 2) == "lj" || S.substr(i, 2) == "nj") {
			count++;
			i += 1;
		}
		else
			count++;
	}

	// 출력
	cout << count;

	return 0;
}