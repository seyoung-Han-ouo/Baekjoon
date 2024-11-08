#include <iostream>
using namespace std;

bool check[4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    string es = "ESTJ";
    string in = "INFP";

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s[i] == es[j]) check[i] = true;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (check[i]) cout << in[i];
        else cout << es[i];
    }

    cout << '\n';

    return 0;
}