#include <iostream>
using namespace std;

int main() {
    int N; // ��� �ð�
    int m, M; // �ʱ� �ƹ� m, �ִ� �ƹ� M, 
    int T, R; // �����ϴ� �ƹ� T, �����ϴ� �ƹ� R

    // �Է�
    cin >> N >> m >> M >> T >> R;

    // ��� �Ұ����� ���
    if (M - m < T) 
        cout << -1;
    else {
        int time = 0; // �ɸ� �ð�
        int X = m; // ���� �ƹ�

        while (N > 0) {
            // �
            if (X + T <= M) {
                X += T; // �ƹ� ����

                N--;
                time++;
            }
            // �޽�
            else {
                if (X - R < m)
                    X = m;
                else
                    X -= R;
                time++;
            }
        }

        // ���
        cout << time;
    }

    return 0;
}