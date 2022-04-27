#include <iostream>
using namespace std;

int main() {
    int sum[81] = { 0 };

    int S1, S2, S3; // �ֻ����� ��
    cin >> S1 >> S2 >> S3;

    int lot = 0; // ���� ���� �߻��� ���� Ƚ��
    int indx = 80; // ���� ���� �߻��ϴ� ��

    for (int i = 1; i <= S1; i++) {
        for (int j = 1; j <= S2; j++) {
            for (int k = 1; k <= S3; k++) {
                int n = i + j + k;
                sum[n]++;

                // ���� ���� �߻��ϴ� �� ã��
                if (sum[n] > lot) {
                    lot = sum[n];
                    indx = n;
                } 

                // ���� ���� �߻��ϴ� ���� ��������� ���� ���� ���� ���� ����
                if (sum[n] == sum[indx] && n < indx)
                    indx = n;
            }
        }
    }

    // ���
    cout << indx;

    return 0;
}