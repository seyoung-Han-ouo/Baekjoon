#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Star {
    double x = 0;
    double y = 0;
};

struct Edge {
    int start = 0;
    int end = 0;
    double weight = 0;
};

int N, parent[1001];
vector<Star> star;
vector<Edge> edge;

bool compare(Edge a, Edge b);
int findParent(int n);
double mst();

bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

int findParent(int n) {
    if (parent[n] == 0 || parent[n] == n) return n;

    return parent[n] = findParent(parent[n]);
}

double mst() {
    double result = 0;

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
    for (int i = 0; i < N; i++) {
        double x, y;
        cin >> x >> y;

        star.push_back({ x, y });
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            double weight = sqrt(pow((star[i].x - star[j].x), 2) + pow((star[i].y - star[j].y), 2));

            edge.push_back({ i + 1, j + 1, weight });
            edge.push_back({ j + 1, i + 1, weight });
        }
    }

    sort(edge.begin(), edge.end(), compare);

    cout << round(mst() * 100) / 100 << '\n';

    return 0;
}