#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, W, H;
    cin >> N >> W >> H;

    double d = sqrt(W * W + H * H);

    while (N--) {
        int n;
        cin >> n;

        if (n <= W || n <= H || n <= d) cout << "DA\n";
        else cout << "NE\n";
    }

    return 0;
}