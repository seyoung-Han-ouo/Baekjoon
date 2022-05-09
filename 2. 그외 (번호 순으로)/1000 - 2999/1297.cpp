#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int DD; // TV�� �밢�� ���� D
    int H, W; //  TV�� ���� ���� H, TV�� �ʺ� ���� W

    // �Է�
    cin >> DD >> H >> W;

    double D = sqrt(H * H + W * W); // �밢�� ����

    double HH = DD / D * H; // ����
    double WW = DD / D * W; // �ʺ�

    // ���
    printf("%d %d\n", (int)HH, (int)WW);

    return 0;
}