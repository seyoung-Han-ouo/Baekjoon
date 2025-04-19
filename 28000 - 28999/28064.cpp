#include <iostream>
#include <string>
using namespace std;

int N;
string arr[101];

bool canLink(string a, string b);

bool canLink(string a, string b) {
    int idx = min(a.length(), b.length());

    for (int i = 1; i <= idx; i++) {
        if (a.substr(0, i) == b.substr(b.length() - i, i)) return true;
        if (b.substr(0, i) == a.substr(a.length() - i, i)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (canLink(arr[i], arr[j])) cnt++;
        }
    }

    cout << cnt << '\n';

    return 0;
}