#include <iostream>
#include <cstdlib>
using namespace std;

long long arr[100000];
pair<long long, long long> result;

void find(int left, int right);

void find(int left, int right) {
    long long sum = 2000000001;

    while (left < right) {
        long long now = arr[left] + arr[right];

        // Ư������ sum���� 0�� �����ٸ�
        if (abs(now) < sum) {
            sum = abs(now);
            result = { arr[left], arr[right] };
        }

        // Ư������ 0�̶��
        if (now == 0) break;

        // Ư������ ���� ���� ����Ʈ �̵�
        if (now > 0) right--;
        else left++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;

    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];

    find(0, N - 1);

    cout << result.first << ' ' << result.second << '\n';

    return 0;
}