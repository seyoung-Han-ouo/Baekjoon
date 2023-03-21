#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M; 
	cin >> N >> M;
	
	string site, password; // ����Ʈ, ��й�ȣ
	unordered_map<string, string> m;
	
	m.reserve(N); // �̸� ���� �÷�����

	// ����Ʈ, ��й�ȣ �Է�
	for (int i = 0; i < N; i++) {
		cin >> site >> password;
		m[site] = password;
	}

	// ��й�ȣ�� ã������ ����Ʈ �ּ��� ��й�ȣ ���
	for (int i = 0; i < M; i++) {
		cin >> site;
		cout << m[site] << "\n";
	}

	return 0;
}