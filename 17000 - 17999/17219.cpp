#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M; 
	cin >> N >> M;
	
	string site, password; // 사이트, 비밀번호
	unordered_map<string, string> m;
	
	m.reserve(N); // 미리 공간 늘려놓기

	// 사이트, 비밀번호 입력
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		m[site] = password;
	}

	// 비밀번호를 찾으려는 사이트 주소의 비밀번호 출력
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << "\n";
	}

	return 0;
}