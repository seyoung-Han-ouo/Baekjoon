#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b);

bool compare(string a, string b) {
    // ���̰� ������ ���� ������
    if (a.length() == b.length())
        return a < b;
    // ���̰� ª�� �ͺ���
    else
        return a.length() < b.length();
}

int main() {
	int N;
	cin >> N;

	vector<string> word(N);

    // �Է�
    for (int i = 0; i < N; i++)
        cin >> word[i];

    // ����
    sort(word.begin(), word.end(), compare);

    // ���
    cout << word[0] << "\n";
    for (int i = 1; i < N; i++) {
        if (word[i] != word[i - 1])
            cout << word[i] << "\n";
    }

	return 0;
}