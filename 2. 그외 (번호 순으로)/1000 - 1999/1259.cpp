#include <iostream>
using namespace std;

int main() {
    // �׽�Ʈ ���̽�
    string T;

    while (true) {
        cin >> T;

        // 0 �Է� �� �ݺ��� ����
        if (T == "0") break;

        int idx = T.length() / 2;
        int count = 0;

        // �Ӹ���Ҽ����� Ȯ���Ѵ�.
        for (int i = 0; i < idx; i++) {
            if (T[i] == T[T.length() - i - 1])
                count++;
        }

        // ���
        if (count == idx)
            cout << "yes\n";
        else
            cout << "no\n";
    }

    return 0;
}