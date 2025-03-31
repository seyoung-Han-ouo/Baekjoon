#include <iostream>
using namespace std;

#define MAX 1000001

int N, M, K;
long long arr[MAX];
long long tree[MAX * 3];

long long init(int start, int end, int node);
void update(int start, int end, int idx, long long data, int node);
long long find(int start, int end, int left, int right, int node);

// 세그먼트 트리 초기화
long long init(int start, int end, int node) {
    // 자식이 없는 노드인 경우
    if (start == end) return tree[node] = arr[start];

    // 좌측 + 우측 구하기
    int mid = (start + end) / 2;
    return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

// 새그먼트 트리 업데이트
void update(int start, int end, int idx, long long data, int node) {
    if (idx < start || idx > end) return;

    tree[node] += data;

    // 자식이 있는 노드인 경우
    if (start != end) {
        int mid = (start + end) / 2;
        update(start, mid, idx, data, node * 2);
        update(mid + 1, end, idx, data, node * 2 + 1);
    }
}

// 구간 합 구하기
long long find(int start, int end, int left, int right, int node) {
    // 탐색 범위가 원하는 구간 밖이라면
    if (left > end || right < start) return 0;

    // 탐색 범위가 원하는 구간 안이라면
    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    return find(start, mid, left, right, node * 2) + find(mid + 1, end, left, right, node * 2 + 1);
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

        if (a == 1) {
            long long data = c - arr[b];

            arr[b] = c;
            update(1, N, b, data, 1);
        }
        else cout << find(1, N, b, c, 1) << '\n';
    }

    return 0;
}