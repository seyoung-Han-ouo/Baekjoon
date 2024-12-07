#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int N, M;
int arr[1001][1001];        // 맵 정보
int check[1001][1001];      // 방문 여부 체크 및 방 번호
int roomSize[1001][1001];   // 각 칸이 포함된 방의 크기

int dy[4] = { 1, -1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

bool canMove(int y, int x);
void findRoom(int sy, int sx, int c);
int breakWall(int y, int x);

// 해당 칸으로 움직일 수 있는가?
bool canMove(int y, int x) {
    return y >= 0 && y < N && x >= 0 && x < M && arr[y][x] == 0;
}

// 이동 가능한 칸(방)의 크기 구하기
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

    // 방을 이루는 각 칸에 방의 크기 표시하기
    while (!save.empty()) {
        int y = save.front().first;
        int x = save.front().second;
        save.pop();

        roomSize[y][x] = cnt;
    }
}

// 벽을 부수면 이동할 수 있는 칸이 몇개인가?
int breakWall(int y, int x) {
    unordered_set<int> room;
    int cnt = 1;

    // 벽 인접 4칸 확인하기
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

    // 입력
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < M; j++)
            arr[i][j] = s[j] - '0';
    }

    int c = 1; // 방 번호
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && roomSize[i][j] == 0) findRoom(i, j, c++);
        }
    }

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) cout << 0; 
            else cout << breakWall(i, j) % 10;
        }
        cout << '\n';
    }

    return 0;
}