#include <iostream>
using namespace std;

bool num[11];

void init();
void check(int start, int end);

void init() {
    for (int i = 0; i < 11; i++) num[i] = false;
}

void check(int start, int end) {
    for (int i = start; i <= end; i++) num[i] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;

        if (n == 0) break;

        string a, b;
        cin >> a >> b;

        if (b == "high") check(n, 10);
        else if (b == "low") check(0, n);
        else {
            if (num[n]) cout << "Stan is dishonest\n";
            else cout << "Stan may be honest\n";

            init();
        }
    }

    return 0;
}