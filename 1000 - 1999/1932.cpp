#include <iostream>
#include <algorithm>
using namespace std;

int semo[501][501] = {};

int main() {
    // �ﰢ���� ũ��
    int n; 
    cin >> n;

    // ���� �ִ밡 �Ǵ� ��ο� �ִ� ���� ��
    int big = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            // �ﰢ���� �̷�� �� �Է�
            scanf("%d", &semo[i][j]);

            // �ﰢ���� ���� ��
            if (j == 1)
                semo[i][j] += semo[i - 1][j];
            // �ﰢ���� ������ ��
            else if (j == i)
                semo[i][j] += semo[i - 1][j - 1];
            // �ﰢ�� �߰��� ����
            else 
                semo[i][j] += max(semo[i - 1][j - 1], semo[i - 1][j]);

            // �ִ��� ã��
            if (semo[i][j] > big && i == n)
                big = semo[i][j];
        }
    }

    // ���
    cout << big << "\n";
        
    return 0;
}