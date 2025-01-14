#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int num = 1;
    for (int i = 0; i < s.length(); ) {
        string n = to_string(num);

        for (int j = 0; j < n.length(); j++) {
            if (s[i] == n[j]) i++;
        }
        
        num++;
    }

    cout << num - 1 << '\n';

    return 0;
}