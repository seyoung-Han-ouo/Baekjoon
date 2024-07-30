#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int start = 0;
    int end = 0;
    int weight = 0;
};

int V, E;
int parent[10001];
vector<Edge> edge;

bool compare(Edge a, Edge b);
int findParent(int n);
int mst();

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int n) {
    if (parent[n] == 0) return n;

    return parent[n] = findParent(parent[n]);
}

int mst() {
    int result = 0;

    for (int i = 0; i < E; i++) {
        int a = findParent(edge[i].start);
        int b = findParent(edge[i].end);

        if (a != b) {
            parent[b] = a;
            result += edge[i].weight;
        }
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edge.push_back({ a, b, c });
    }

    sort(edge.begin(), edge.end(), compare);

    cout << mst() << '\n';

    return 0;
}