#include <iostream>
#include <vector>
using namespace std;

int sudoku[9][9];
vector<pair<int, int>> zero;

bool canFill(int y, int x, int num);
void fillZero(int idx);

bool canFill(int y, int x, int num) {
    for (int i = 0; i < 9; i++) {
        if (sudoku[y][i] == num && i != x) return false;
        if (sudoku[i][x] == num && i != y) return false;

        int ny = y / 3 * 3 + i / 3;
        int nx = x / 3 * 3 + i % 3;

        if (sudoku[ny][nx] == num && nx != x && ny != y) return false;
    }

    return true;
}

void fillZero(int idx) {
    if (idx == zero.size()) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) cout << sudoku[i][j];
            cout << '\n';
        }

        exit(0);
    }

    int y = zero[idx].first;
    int x = zero[idx].second;

    for (int i = 1; i <= 9; i++) {
        if (canFill(y, x, i)) {
            sudoku[y][x] = i;
            fillZero(idx + 1);
            sudoku[y][x] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < 9; j++) {
            sudoku[i][j] = (s[j] - '0');

            if (sudoku[i][j] == 0) zero.push_back({ i, j });
        }
    }

    fillZero(0);

    return 0;
}