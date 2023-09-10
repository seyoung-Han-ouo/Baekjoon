#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;
int cnt = 0;

void visit(int x, int y, int size);

void visit(int x, int y, int size) {
    if (x == c && y == r) {
        cout << cnt << '\n';
        return;
    }

    if (c < x + size && c >= x && r < y + size && r >= y) {
        visit(x, y, size / 2);
        visit(x + size / 2, y, size / 2);
        visit(x, y + size / 2, size / 2);
        visit(x + size / 2, y + size / 2, size / 2);
    }
    else cnt += size * size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> r >> c;

    visit(0, 0, pow(2, N));

    return 0;
}