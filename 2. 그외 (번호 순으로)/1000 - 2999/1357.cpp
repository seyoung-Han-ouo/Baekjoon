#include <iostream>
#include <cmath>
using namespace std;

// ��� �ڸ����� �������� ����� �Լ�
int Rev(int num) {
    int rNum = 0;

    int idx = 0; // num�� ����
    int num1 = num;

    // num ���� ���ϱ�
    for (int i = 0; ; i++) {
        num1 /= 10;
        idx++;

        if (num1 == 0)
            break;
    }

    // ���ڸ� �������� �ٲٱ�
    for (int i = idx - 1; i >= 0; i--) {
        rNum += num % 10 * pow(10, i);
        num /= 10;
    }

    return rNum;
}

int main() {
    int X, Y;
    cin >> X >> Y;

    // ���
    cout << Rev(Rev(X) + Rev(Y)) << endl;

    return 0;
}