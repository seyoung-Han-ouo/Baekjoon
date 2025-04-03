#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    string cheese = "Cheese";

    cin >> N;

    while (N--) {
        string s;
        cin >> s;

        // 토핑의 이름이 Cheese보다 짧은 경우
        if (s.length() < cheese.length()) continue;

        // 토핑의 이름이 Cheese로 끝나는지 확인
        int check = 0;
        for (int i = 0; i < cheese.length(); i++) {
            if (s[s.length() - cheese.length() + i] != cheese[i]) break;
            check++;
        }

        // 토핑의 이름이 Cheese로 끝난다면
        if (check == 6) m[s] = 1;
    }

    // 출력
    if (m.size() >= 4) cout << "yummy\n";
    else cout << "sad\n";

    return 0;
}