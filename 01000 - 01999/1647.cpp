#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int start = 0;
    int end = 0;
    int weight = 0;
};

int N, M;
int parent[100001];
vector<Edge> edge;

bool compare(Edge a, Edge b);
int findParent(int n);
int mst();

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// 루트 노드 찾기
int findParent(int n) {
    if (parent[n] == 0) return n;

    return parent[n] = findParent(parent[n]);
}

// 최소 스패닝 트리
int mst() {
    int result = 0;
    int mx = 0;

    for (int i = 0; i < M; i++) {
        int a = findParent(edge[i].start);
        int b = findParent(edge[i].end);

        // 두 노드의 루트 노드가 같지 않다면 서로 연결한다.
        if (a != b) {
            parent[b] = a;
            result += edge[i].weight;
            mx = max(mx, edge[i].weight);
        }
    }

    return result - mx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({ a, b, c });
    }

    sort(edge.begin(), edge.end(), compare);

    cout << mst() << '\n';

    return 0;
}