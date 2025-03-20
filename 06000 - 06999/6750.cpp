#include <iostream>
using namespace std;

char letter[7] = { 'I', 'O', 'S', 'H', 'Z', 'X', 'N' };

bool canUse(char c);

bool canUse(char c) {
    for (int i = 0; i < 7; i++) {
        if (c == letter[i]) return true;
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (!canUse(s[i])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    return 0;
}