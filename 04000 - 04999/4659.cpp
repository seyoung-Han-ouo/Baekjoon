#include <iostream>
using namespace std;

bool isVowel(char t);
bool isGoodPassword(string s);

// �ش� ���ڰ� �������� Ȯ���ϴ� �Լ�
bool isVowel(char t) {
    char mo[5] = { 'a' ,'e', 'i', 'o', 'u' };

    for (char c : mo) 
        if (t == c) return true;

    return false;
}


// ���� �н��������� Ȯ���ϴ� �Լ�
bool isGoodPassword(string s) {
    bool isGood = false;
    int mo = 0;
    int za = 0;

    for (int i = 0; i < s.length(); i++) {
        if (isVowel(s[i])) {
            isGood = true;

            if (za > 0) {
                mo = 1;
                za = 0;
            }
            else mo++;
        }
        else {
            if (mo > 0) {
                za = 1;
                mo = 0;
            }
            else za++;
        }

        // ���� ���� �н��������� Ȯ���Ѵ�.
        if (mo > 2 || za > 2) return false;
        if ((mo > 1 || za > 1) && s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') return false;
    }

    return isGood;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        string s;
        cin >> s;

        if (s == "end") break;

        cout << '<' << s << '>';

        if (isGoodPassword(s))
            cout << " is acceptable.\n";
        else
            cout << " is not acceptable.\n";
    }

    return 0;
}