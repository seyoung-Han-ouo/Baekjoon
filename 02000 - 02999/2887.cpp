#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
    int start = 0;
    int end = 0;
    long long weight = 0;
};

int N, parent[100001];
vector<pair<int, int>> x, y, z;
vector<Edge> edge;

bool compare(Edge a, Edge b);
int findParent(int n);
long long mst();

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;

    return parent[n] = findParent(parent[n]);
}

long long mst() {
    long long result = 0;

    for (int i = 0; i < edge.size(); i++) {
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

    cin >> N;
    for (int i = 1; i < N + 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        x.push_back({ a, i });
        y.push_back({ b, i });
        z.push_back({ c, i });
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    sort(z.begin(), z.end());

    for (int i = 0; i < N - 1; i++) {
        edge.push_back({ x[i].second, x[i + 1].second, x[i + 1].first - x[i].first });
        edge.push_back({ y[i].second, y[i + 1].second, y[i + 1].first - y[i].first });
        edge.push_back({ z[i].second, z[i + 1].second, z[i + 1].first - z[i].first });
    }

    sort(edge.begin(), edge.end(), compare);

    cout << mst() << '\n';

    return 0;
}