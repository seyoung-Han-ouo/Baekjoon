#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string f[51]; // ���� �̸� ����
    bool difr[51] = { false }; // ?�� ���� ��ġ ����

    int N; // ���� �̸��� ���� N
    cin >> N; 

    for (int i = 0; i < N; i++) {
        // �Է�
        cin >> f[i];

        // �Էµ� �����̸��� ���ؼ� ?�� �ٲ� �κ� ã��
        if (i > 0) {
            for (int j = 0; j < f[i - 1].length(); j++) {
                if (f[i][j] != f[i - 1][j])
                    difr[j] = true;
            }
        }
    }

    // ���
    for (int i = 0; i < f[0].length(); i++) {
        if (difr[i] == true)
            printf("?");
        else
            cout << f[0][i];
    }

    return 0;
}