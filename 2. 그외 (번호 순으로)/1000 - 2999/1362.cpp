#include <iostream>
using namespace std;

int main() {
    double o, w; // ���� ü�� o, ���� ü�� w
    int scenario = 1; // �ó����� ��ȣ
    
    while (true) {
        bool isRIP = false; // ���� ���� ����

        cin >> o >> w;

        // �ó����� ����
        if (o == 0 && w == 0) break;

        while (true) {
            char EF; // �꿡�� ���� �� �ۿ�
            int n;

            cin >> EF >> n;

            // �ó����� �ϳ� ����
            if (EF == '#' && n == 0) break;

            // ���� ����ִ� ��� �Է��� �ۿ��� �����Ѵ�.
            if (!isRIP) {
                if (EF == 'E') w -= n; // �
                else if (EF == 'F') w += n; // ����

                if (w <= 0) isRIP = true; // ���
            }
        }
        
        // ���
        if (isRIP)
            printf("%d RIP\n", scenario); // �� ���
        else if (w > o / 2 && w < o * 2)
            printf("%d :-)\n", scenario); // �ູ
        else
            printf("%d :-(\n", scenario); // ����

        scenario++;
    }

    return 0;
}