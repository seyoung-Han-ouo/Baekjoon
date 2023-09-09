#include <iostream>
#include <cmath>
using namespace std;

string s;

void cantor(int n);

void cantor(int n) {
    if (n == 0) {
        s += "-";
        return;
    }

    cantor(n - 1);
    for (int i = 0; i < pow(3, n - 1); i++) s += " ";
    cantor(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;

    while (cin >> N) {
        s = "";

        cantor(N);
        cout << s << '\n';
    }

    return 0;
}