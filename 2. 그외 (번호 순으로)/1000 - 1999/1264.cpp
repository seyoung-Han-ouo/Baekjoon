#include <iostream>
#include <string>
using namespace std;

char vowel[5] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
    // �׽�Ʈ ���̽�
    string T;

    while (true) {
        getline(cin, T); // ���� ���� ���ڿ�

        // # �Է� �� �ݺ��� ����
        if (T == "#") break;

        int count = 0;  // ������ ����

        for (int i = 0; i < T.length(); i++) {
            // �빮�ڸ� �ҹ��ڷ� ��ȯ
            if (T[i] >= 'A' && T[i] <= 'Z')
                T[i] += 32;

            // ������ ����
            for (int j = 0; j < 5; j++) {
                if (T[i] == vowel[j])
                    count++;
            }
        }

        // ���
        printf("%d\n", count);
    }

    return 0;
}