#include <iostream>
using namespace std;

string cover(int cnt);

// 폴리오미노로 문자 덮기
string cover(int cnt) {
    string s = "";

    while (cnt >= 4) {
        s += "AAAA";
        cnt -= 4;
    }

    while (cnt > 0) {
        s += "BB";
        cnt -= 2;
    }

    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;

    int cnt = 0;
    string result;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'X') cnt++;
        else {
            if (cnt % 2 == 1) break;

            result += cover(cnt);
            result += ".";

            cnt = 0;
        }
    }

    // 출력
    if (cnt % 2 == 1) cout << "-1\n";
    else {
        result += cover(cnt);

        cout << result << '\n';
    }

    return 0;
}