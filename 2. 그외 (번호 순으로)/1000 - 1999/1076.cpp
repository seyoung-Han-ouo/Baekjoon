#include <iostream>
#include <cmath>
using namespace std;

// ������ ��
string color[10] = { "black", "brown", "red", "orange", "yellow",
                    "green", "blue", "violet", "grey", "white" };

int main() {
    int sum = 0; // ������ ��

    for (int i = 0; i < 3; i++) {
        // �Է�
        string c;
        cin >> c;

        // �Է��� ���� color[]�� �� �� �ε����� �ش��ϴ� �� ã��
        int j = 0;
        for (j; j < 10; j++)
            if (c == color[j]) break;

        // ������ �� ���
        if (i <= 1)
            sum += (j * pow(10, 1 - i));
        else { // ���
            cout << sum;

            if (sum > 0) {
                for (int k = 0; k < j; k++)
                    cout << "0";
            }
        }
    }

    return 0;
}