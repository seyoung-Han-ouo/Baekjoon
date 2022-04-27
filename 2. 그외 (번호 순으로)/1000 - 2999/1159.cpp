#include <iostream>
using namespace std;

int main() {
    int alpha[26] = {};  // ���� ù ���ڰ� ���� ��� ��
    bool giveUp = false; // ���� ���� ���� ����

    int N; // ������ ��
    cin >> N;

    // �Է�
    for (int i = 0; i < N; i++) {
        string name;
        cin >> name;

        alpha[name[0] - 'a']++;

        // ���� ù ���ڰ� ���� ������ 5���� ���� ��
        if (alpha[name[0] - 'a'] >= 5) 
            giveUp = true;
    }

    // ���
    if (giveUp == false)  // ���� �ټ� ���� ������ �� ���� ���
        cout << "PREDAJA";
    else {
        for (int i = 0; i < 26; i++) {
            if (alpha[i] >= 5)
                cout << (char)(i + 'a');
        }
    }

    return 0;
}