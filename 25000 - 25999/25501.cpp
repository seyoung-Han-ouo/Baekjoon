#include <iostream>
using namespace std;

int cnt;

int isPalindrome(string s, int l, int r);

int isPalindrome(string s, int l, int r) {
    cnt = 1;

    while (l < r) {
        if (s[l++] != s[r--]) return 0;
        cnt++;
    }

    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        string S;
        cin >> S;

        cout << isPalindrome(S, 0, S.length() - 1) << ' ';
        cout << cnt << '\n';
    }

    return 0;
}