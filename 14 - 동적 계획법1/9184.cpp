#include <iostream>
using namespace std;

// �̹� ã�� ���� �� ����� �ʿ䰡 ���� �����Ѵ�.
int arr[51][51][51] = {0};

// ����Լ�
int w (int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        arr[a][b][c] = 1;
        return arr[a][b][c];
    }

    if (a > 20 || b > 20 || c > 20)
        return w(20, 20, 20);

    // �̹� ����� ���� �ִ� ���� ��͸� ���� �ʰ� �迭���� ���ڸ� �̾� ����Ѵ�.
    if (arr[a][b][c] != 0)
        return arr[a][b][c];

    if (a < b && b < c)
        return arr[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

    return arr[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
    int a, b, c;

    while(true) {
        // �Է�
        cin >> a >> b >> c;

        // a, b, c�� ��� -1�̸� �ݺ� ����
        if (a == -1 && b == -1 && c == -1) break;

        // ���
        if (a < 0 || b < 0 || c < 0) // a, b, c �� �ϳ��� 0���� ���� ��
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(0, 0, 0)); 
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
    }

    return 0;
}