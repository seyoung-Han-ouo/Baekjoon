#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, I, A, R, C;
    cin >> H >> I >> A >> R >> C;
    cout << H * I - A * R * C << '\n';

    return 0;
}