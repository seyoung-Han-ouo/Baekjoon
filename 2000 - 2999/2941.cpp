#include <iostream>
#include <string>
using namespace std;

int main() {
	// ũ�ξ�Ƽ�� ���ĺ� S
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

	// ���
	cout << count;

	return 0;
}