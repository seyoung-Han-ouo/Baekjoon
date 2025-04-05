#include <iostream>
using namespace std;

int H, W;
int sky[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> H >> W;

    for (int i = 1; i <= H; i++) {
        sky[i][0] = -1;

        for (int j = 1; j <= W; j++) {
            char c;
            cin >> c;

            if (c == 'c') sky[i][j] = 0;
            else if (sky[i][j - 1] >= 0) sky[i][j] = sky[i][j - 1] + 1;
            else sky[i][j] = -1;
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) cout << sky[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}