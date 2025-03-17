#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define MAX 10001

int V, E, id;
int parent[MAX];
bool finish[MAX];		// scc 여부
vector<int> arr[MAX];	// 간선
vector<vector<int>> scc;
stack<int> st;

int dfs(int now);

int dfs(int now) {
	parent[now] = ++id;
	st.push(now);

	int p = parent[now];
	for (int n : arr[now]) {
		if (parent[n] == 0) p = min(p, dfs(n));		// 첫 방문인 정점
		else if (!finish[n]) p = min(p, parent[n]);	// 아직 scc가 되지 않은 정점
	}

	if (p == parent[now]) {
		vector<int> sc;

		// 찾은 집합을 scc에 추가하기
		while (true) {
			int t = st.top();
			st.pop();

			sc.push_back(t);
			finish[t] = true;

			if (t == now) break;
		}

		sort(sc.begin(), sc.end());

		scc.push_back(sc);
	}

	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> V >> E;

	while (E--) {
		int a, b;
		cin >> a >> b;

		arr[a].push_back(b);
	}

	// scc 찾기
	for (int i = 1; i <= V; i++) {
		if (parent[i] == 0) dfs(i);
	}

	sort(scc.begin(), scc.end());

	// 출력
	cout << scc.size() << '\n';
	for (int i = 0; i < scc.size(); i++) {
		for (int n : scc[i]) cout << n << ' ';
		cout << "-1\n";
	}

	return 0;
}