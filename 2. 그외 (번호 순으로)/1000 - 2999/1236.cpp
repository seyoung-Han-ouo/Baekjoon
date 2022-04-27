#include <iostream>
using namespace std;

int main() {
    bool sero[51] = { false };
    bool garo[51] = { false };

    // ���� ũ�� N, ���� ũ�� M
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        // ������ �ִ� ĭ üũ
        for (int j = 0; j < M; j++) {
            if (s[j] == 'X') {
                sero[i] = true;
                garo[j] = true;
            }
        }
    }

    // �߰��ؾ� �ϴ� ������ �ּڰ� ã��
    int count1 = N;
    for (int i = 0; i < N; i++)
        if (sero[i] == true) count1--;

    int count2 = M;
    for (int i = 0; i < M; i++)
        if (garo[i] == true) count2--;

    // ���
    if (count1 > count2)
        cout << count1;
    else
        cout << count2;

    return 0;
}