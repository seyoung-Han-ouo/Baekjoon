#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int main() {
    // �Է�
    string s;
    cin >> s;

    // �Է��� ���� 0�� ��
    if (s == "0")
        cout << 0;
    else {
        for (int i = 0; i < s.length(); i++) {
            // 2������ ��ȯ
            string num = (bitset<3>((int)s[i])).to_string();

            // ���
            if (i == 0) {
                int n = stoi(num);
                cout << n;
            }
            else
                cout << num;
        }
    }

    return 0;
}