#include <iostream>
using namespace std;

int main() {
    while (true) {
        string N; // ȣ���ǿ� �� ���� N
        cin >> N;

        // 0 �Է� �� �ݺ� ����
        if (N == "0") break;

        // ȣ���� �ʺ�
        int num = N.length() + 1;

        for (int i = 0; i < N.length(); i++) {
            if (N[i] == '0')
                num += 4;
            else if (N[i] == '1')
                num += 2;
            else 
                num += 3;
        }

        // ���
        printf("%d\n", num);
    }

    return 0;
}