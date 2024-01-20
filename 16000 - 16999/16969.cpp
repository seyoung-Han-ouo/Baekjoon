#include <iostream>
using namespace std;

#define MOD 1000000009

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    long long result = (s[0] == 'd') ? 10 : 26;

    for (int i = 1; i < s.length(); i++) {
        int isSame = (s[i] == s[i - 1]);

        if (s[i] == 'd') 
            result *= (10 - isSame);
        else 
            result *= (26 - isSame);

        result %= MOD;
    }

    cout << result << '\n';

    return 0;
}