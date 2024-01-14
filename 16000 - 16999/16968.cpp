#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int result = (s[0] == 'd') ? 10 : 26;

    for (int i = 1; i < s.length(); i++) {
        bool isSame = (s[i] == s[i - 1]);

        if (s[i] == 'd') 
            result *= (10 - isSame);
        else 
            result *= (26 - isSame);
    }

    cout << result << '\n';

    return 0;
}