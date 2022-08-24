#include <iostream>
using namespace std;

int main() {
    int N, c; // ������ ���� N, Ŭ�������� ũ�� c
    int file[51]; // ������ ũ��

    // �Է�
    cin >> N;
    for (int i = 0; i < N; i++)
        scanf("%d", &file[i]);
    cin >> c;

    long long cnt = 0; // ��� ���� Ŭ������ ��

    // ��� ���� Ŭ������ �� ���ϱ�
    for (int i = 0; i < N; i++) {
        // ���� ũ�Ⱑ 0�̸� Ŭ�����͸� ������� �ʴ´�.
        if (file[i] == 0) continue;

        if (file[i] <= c) cnt++;
        else {
            cnt += (file[i] / c);

            if (file[i] % c != 0) cnt++;
        }
    }

    // ���
    cout << cnt * c << endl;

    return 0;
}