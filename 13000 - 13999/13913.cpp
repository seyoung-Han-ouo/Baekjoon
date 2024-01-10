#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100001

vector<int> result;
int saveLine[MAX];
bool check[MAX];

void findPath(int start, int i);
void printPath();
void bfs(int start, int end);

// �湮 ��� ���ϱ�
void findPath(int start, int i) {
    while (i != start) {
        result.push_back(i);
        i = saveLine[i];
    }

    result.push_back(i);
}

// �湮 ��� ����ϱ�
void printPath() {
    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';
}

void bfs(int start, int end) {
    queue<pair<int, int>> q;
    q.push({ start, 0 });
    check[start] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int time = q.front().second;
        q.pop();

        // ������ �ִ� ��ġ�� ��������
        if (x == end) {
            cout << time << '\n';

            findPath(start, x);
            printPath();
        }

        int nx[3] = { x - 1, x + 1, x * 2 }; // ������ �湮�� ��ġ

        for (int i = 0; i < 3; i++) {
            if (nx[i] >= 0 && nx[i] < MAX && !check[nx[i]]) {
                q.push({ nx[i], time + 1 });

                check[nx[i]] = true;
                saveLine[nx[i]] = x;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K;
    cin >> N >> K;

    bfs(N, K);

    return 0;
}