#include <iostream>
using namespace std;

int main() {
    // �Ͼ� ĭ �� ���� ��
    int white = 0; 

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;

            // �Է��� ������ ��ġ�� �Ͼ� ĭ���� Ȯ���Ѵ�.
            if (c == 'F') {
                if (i % 2 == 0 && j % 2 == 0)
                    white++;
                if (i % 2 == 1 && j % 2 == 1)
                    white++;
            }
        }
    }

    // ���
    cout << white;

    return 0;
}