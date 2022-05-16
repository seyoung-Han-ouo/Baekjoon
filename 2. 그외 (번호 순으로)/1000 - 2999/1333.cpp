#include <iostream>
using namespace std;

int main() {
    // �� �뷡�� N��, �뷡�� ���� L��, ��ȭ���� �︮�� ���� D��
    int N, L, D;
    cin >> N >> L >> D;

    int btime; // ��ȭ���� �︮�� �ð�
    bool isfind = false; // ��ȭ���� ���� �� �ִ� �ð��� ã�Ҵ°�?

    for (int i = 1; ; i++) {
        btime = D * i;

        for (int j = 1; j <= N; j++) {
            int mtime = L * j + 5 * (j - 1); // �뷡�� ������ �ð�

            // �뷡�� �뷡 ������ ������ ������ btime�� ���ԵǴ��� Ȯ��
            if (btime >= mtime && btime < mtime + 5) {
                isfind = true;
                break;
            }
        }

        // ��ȭ�� ��� �ð��� ã�Ұų� �ٹ��� ������ ��
        if (btime > N * L + (5 * (N - 1)) || isfind == true)
            break;
    }

    // ���
    printf("%d\n", btime);

    return 0;
}