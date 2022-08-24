#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int num[160] = {};
    bool isZero = false;

    // �� ������ �� �� �� ���� a�� �����Ѵ�.
    if (a.length() < b.length()) {
        string c = a;
        a = b;
        b = c;
    }

    // ����ϱ� ���ϰ� �ϱ� ���� �迭�� �����´�.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int idx = a.length();

    // ������ ����
    for (int i = 0; i < a.length(); i++) {
        if (i < b.length())
            num[i] += (a[i] - '0') + (b[i] - '0');
        else
            num[i] += (a[i] - '0');

        
        if (num[i] != 0)
            isZero = true;

        // �޾ƿø�
        if (num[i] >= 2) {
            num[i] -= 2;
            num[i + 1]++;

            if (i == a.length() - 1) idx++;
        }
    }

    // ���
    // ���� 0���� Ȯ���Ѵ�.
    if (isZero == false)
        cout << "0\n";
    else {
        // �ʿ� ���� 0 �����ϱ� ���� ����
        bool start = false;

        // ���
        for (int i = idx - 1; i >= 0; i--) {
            if (num[i] == 1)
                start = true;

            if (start == true)
                printf("%d", num[i]);
        }
    }

    return 0;
}