#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int H, W, N, M;
    cin >> H >> W >> N >> M;
    cout << ((H - 1) / (N + 1) + 1) * ((W - 1) / (M + 1) + 1) << '\n';

    return 0;
}