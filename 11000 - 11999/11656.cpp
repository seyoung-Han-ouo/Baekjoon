#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string sArr[1001];

int main() {
	string s;
	cin >> s;

	int sIdx = s.length();

	for (int i = 0; i < sIdx; i++)
		for (int j = i; j < sIdx; j++)
			sArr[i].push_back(s[j]);

	sort(sArr, sArr + sIdx);

	for (int i = 0; i < sIdx; i++)
		cout << sArr[i] << "\n";

	return 0;
}