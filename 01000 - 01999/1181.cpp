#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string a, string b);

bool compare(string a, string b) {
    // 길이가 같으면 사전 순으로
    if (a.length() == b.length())
        return a < b;
    // 길이가 짧은 것부터
    else
        return a.length() < b.length();
}

int main() {
	int N;
	cin >> N;

	vector<string> word(N);

    // 입력
    for (int i = 0; i < N; i++)
        cin >> word[i];

    // 정렬
    sort(word.begin(), word.end(), compare);

    // 출력
    cout << word[0] << "\n";
    for (int i = 1; i < N; i++) {
        if (word[i] != word[i - 1])
            cout << word[i] << "\n";
    }

	return 0;
}