#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;          // �������� ��
    int tSize[6];   // Ƽ���� ����� ��û���� ��
    int T, P;       // Ƽ������ ���� ���� ��

    // �Է�
    cin >> N;
    for (int i = 0; i < 6; i++) cin >> tSize[i];
    cin >> T >> P;

    // Ƽ���� ���� ���� ���ϱ�
    int tCnt = 0;
    for (int i = 0; i < 6; i++)
        tCnt += (tSize[i] / T + (tSize[i] % T > 0));

    // ���
    cout << tCnt << '\n';
    cout << N / P << ' ' << N % P << '\n';

    return 0;
}