#include <iostream>
using namespace std;

int main() {
    int num[5]; // �ټ� ���� �ڿ��� 
    int smallNum = 101; // �Է��� �� �� ���� ���� �� 
    int small = 100000000; // ���� ���� ��κ��� ��� ����

    // �Է�
    for (int i = 0; i < 5; i++) {
        cin >> num[i];

        // �Է��� ���� �߿��� ���� ���� �� ã��
        if (num[i] < smallNum)
            smallNum = num[i];
    }

    // ���� ���� ��κ��� ��� ã��
    for (int i = smallNum; ; i++) {
        // n�� num[]�� ���ڷ� ������ �������� Ƚ�� ���ϱ�
        int count = 0;
        for (int j = 0; j < 5; j++)
            if (i % num[j] == 0) count++;

        // ��κ��� ��� ã���� ��
        if (count >= 3) {
            small = i;
            break;
        }
    }

    // ���
    cout << small;

    return 0;
}