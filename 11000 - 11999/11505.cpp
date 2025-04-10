#include <iostream>
using namespace std;

#define MAX 1000001
#define MOD 1000000007

int N, M, K;
long long arr[MAX];
long long tree[MAX * 4];

long long init(int start, int end, int node);
void update(int start, int end, int node, int idx, long long data);
long long find(int start, int end, int node, int left, int right);

// 세그먼트 트리 초기화
long long init(int start, int end, int node) {
    if (start == end) return tree[node] = arr[start];

    int mid = (start + end) / 2;
    return tree[node] = (init(start, mid, node * 2) % MOD * init(mid + 1, end, node * 2 + 1) % MOD) % MOD;
}

// 세그먼트 트리 업데이트
void update(int start, int end, int node, int idx, long long data) {
    if (idx < start || idx > end) return;

    if (start == end) {
        tree[node] = data;
        return;
    }

    int mid = (start + end) / 2;
    update(start, mid, node * 2, idx, data);
    update(mid + 1, end, node * 2 + 1, idx, data);

    tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % MOD;
}

// 구간 곱 구하기
long long find(int start, int end, int node, int left, int right) {
    // 탐색 범위가 원하는 구간 밖이라면
    if (left > end || right < start) return 1;

    // 탐색 범위가 원하는 구간 안이라면
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return (find(start, mid, node * 2, left, right) * find(mid + 1, end, node * 2 + 1, left, right)) % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);

    for (int i = 0; i < M + K; i++) {
        long long a, b, c;
        cin >> a >> b >> c;

        if (a == 1)
            update(1, N, 1, b, c);
        else 
            cout << find(1, N, 1, b, c) % MOD << '\n';
    }

    return 0;
}