#include <iostream>
using namespace std;

int main() {
    string N;
    cin >> N;

    bool isYou = false; // ������ ����
    int m1 = 1; // �պκ� �ڸ����� ��

    for (int i = 0; i < N.length() - 1; i++) {
        m1 *= N[i] - '0';

        // �޺κ� �ڸ����� ��
        int m2 = 1;
        for (int j = i + 1; j < N.length(); j++)
            m2 *= N[j] - '0';

        // ���������� Ȯ���Ѵ�.
        if (m1 == m2) {
            isYou = true;
            break;
        }
    }

    // ���
    if (isYou == true)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}