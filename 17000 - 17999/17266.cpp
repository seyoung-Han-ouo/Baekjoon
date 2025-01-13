#include <iostream>
using namespace std;

int N, M;
bool arr[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;

    int last = 0;
    int h = 0;

    while (M--) {
        int x;
        cin >> x;

        arr[x] = true;

        // ���ε� ������ �Ÿ� üũ�ϱ�
        if (!arr[last])
            h = max(h, x - last);
        else
            h = max(h, (x - last) / 2 + (x - last) % 2);

        last = x;
    }

    // ���� ���� ������ ���ε���� �Ÿ� üũ�ϱ�
    if (!arr[N])
        h = max(h, N - last);
    else
        h = max(h, (N - last) / 2 + (N - last) % 2);

    // ���
    cout << h << '\n';

    return 0;
}