#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int DD; // TV의 대각선 길이 D
    int H, W; //  TV의 높이 비율 H, TV의 너비 비율 W

    // 입력
    cin >> DD >> H >> W;

    double D = sqrt(H * H + W * W); // 대각선 비율

    double HH = DD / D * H; // 높이
    double WW = DD / D * W; // 너비

    // 출력
    printf("%d %d\n", (int)HH, (int)WW);

    return 0;
}