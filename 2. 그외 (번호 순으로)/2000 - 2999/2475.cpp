#include <iostream>
using namespace std;

int main() {
    // �� ���ڸ� ������ ������ ��
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        // ������ȣ�� ó�� 5�ڸ�
        int num;
        cin >> num;

        sum += (num * num);
    }

    //  �� ���ڸ� ������ ������ ���� 10���� ���� ������ ���
    cout << sum % 10;

    return 0;
}