#include <iostream>
#include <vector>
using namespace std;

#define MAX 100001

int arr[MAX];
vector<pair<int, int>> tree(MAX * 4);

pair<int, int> init(int start, int end, int node);
pair<int, int> find(int start, int end, int left, int right, int node);

pair<int, int> init(int start, int end, int node) {
    if (start == end) return tree[node] = { arr[start], arr[start] };

    int mid = (start + end) / 2;
    pair<int, int> left = init(start, mid, node * 2);
    pair<int, int> right = init(mid + 1, end, node * 2 + 1);

    return tree[node] = { min(left.first, right.first), max(left.second, right.second) };
}

pair<int, int> find(int start, int end, int left, int right, int node) {
    if (left > end || right < start) return { 1000000000, 0 };

    if (left <= start && end <= right) return tree[node];

    int mid = (start + end) / 2;
    pair<int, int> l = find(start, mid, left, right, node * 2);
    pair<int, int> r = find(mid + 1, end, left, right, node * 2 + 1);

    return { min(l.first, r.first), max(l.second, r.second) };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) cin >> arr[i];

    init(1, N, 1);

    while (M--) {
        int a, b;
        cin >> a >> b;

        pair<int, int> result = find(1, N, a, b, 1);
        cout << result.first << ' ' << result.second << '\n';
    }

    return 0;
}