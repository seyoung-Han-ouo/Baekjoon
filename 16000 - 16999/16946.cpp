#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M;
int arr[1001][1001];        // �� ����
int check[1001][1001];      // �湮 ���� üũ �� �� ��ȣ
int roomSize[1001][1001];   // �� ĭ�� ���Ե� ���� ũ��

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool canMove(int y, int x);
void findRoom(int sy, int sx, int c);
int breakWall(int y, int x);

// �ش� ĭ���� ������ �� �ִ°�?
bool canMove(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && arr[y][x] == 0;
}

// �̵� ������ ĭ(��)�� ũ�� ���ϱ�
void findRoom(int sy, int sx, int c) {
    queue <pair<int, int>> q, save;
    int cnt = 1;

    q.push({ sy, sx });
    save.push({ sy, sx });
    check[sy][sx] = c;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (canMove(ny, nx) && check[ny][nx] != c) {
                q.push({ ny, nx });
                save.push({ ny, nx });
                check[ny][nx] = c;
                cnt++;
            }
        }
    }

    // ���� �̷�� �� ĭ�� ���� ũ�� ǥ���ϱ�
    while (!save.empty()) {
        int y = save.front().first;
        int x = save.front().second;
        save.pop();

        roomSize[y][x] = cnt;
    }
}

// ���� �μ��� �̵��� �� �ִ� ĭ�� ��ΰ�?
int breakWall(int y, int x) {
    unordered_set<int> room;
    int cnt = 1;

    // �� ���� 4ĭ Ȯ���ϱ�
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (canMove(ny, nx) && room.find(check[ny][nx]) == room.end()) {
            room.insert(check[ny][nx]);
            cnt += roomSize[ny][nx];
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // �Է�
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            arr[i][j] = s[j] - '0';
    }

    int c = 1; // �� ��ȣ
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && roomSize[i][j] == 0) findRoom(i, j, c++);
        }
    }

    // ���
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) cout << 0; 
            else cout << breakWall(i, j) % 10;
        }
        cout << '\n';
    }

    return 0;
}