#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, B;
    cin >> N >> B;

    string s = "";

    while (N > 0) {
        int mod = N % B;

        if (mod < 10)
            s += (mod + '0');
        else
            s += (mod - 10 + 'A');

        N /= B;
    }

    for (int i = s.length() - 1; i >= 0; i--) cout << s[i];

    return 0;
}