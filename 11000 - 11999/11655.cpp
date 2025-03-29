#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    getline(cin, s);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += 13;

            if (s[i] < 'a' || s[i] > 'z') s[i] -= 26;
        }
        else if (s[i] >= 'A' && s[i] <= 'Z') {
            s[i] += 13;

            if (s[i] > 'Z') s[i] -= 26;
        }

        cout << s[i];
    }
    
    return 0;
}