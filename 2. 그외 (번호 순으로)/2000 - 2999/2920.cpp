#include <iostream>
using namespace std;

int main() {
    // ������ ������ ascending����, descending���� �Ǻ�
    bool isAc = false;
    bool isDs = false;

    // �Է�
    int num1;
    cin >> num1;

    for (int i = 0; i < 7; i++) {
        // ������ȣ�� ó�� 5�ڸ�
        int num2;
        cin >> num2;

        if (num1 < num2)
            isAc = true;
        else if (num1 > num2)
            isDs = true;

        num1 = num2;
    }

    // ���
    if (isAc && isDs) // isAc, isDs�� �Ѵ� ���̸� mixed�̴�.
        cout << "mixed\n";
    else if (isAc)
        cout << "ascending\n";
    else
        cout << "descending\n";

    return 0;
}