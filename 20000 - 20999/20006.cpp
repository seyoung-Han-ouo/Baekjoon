#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Player {
    int level = 0;
    string name;
};

int p, m;
vector<Player> room[301];

bool compare(Player a, Player b);

bool compare(Player a, Player b) {
    return a.name < b.name;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> p >> m;

    while (p--) {
        int l;
        string n;

        cin >> l >> n;

        for (int i = 0; i < 301; i++) {
            // 이미 정원이 찬 방인 경우
            if (room[i].size() == m) continue;

            // 새로운 방을 만들어야 하거나 방 매칭 성공 시
            if (room[i].size() == 0 || (room[i][0].level - 10 <= l && l <= room[i][0].level + 10)) {
                room[i].push_back({ l, n });
                break;
            }
        }
    }

    for (int i = 0; i < 301; i++) {
        // 텅 빈 방은 아직 생성되지 않은 방과 같기에
        if (room[i].size() == 0) break;

        sort(room[i].begin(), room[i].end(), compare);

        // 출력
        if (room[i].size() == m) cout << "Started!\n";
        else cout << "Waiting!\n";

        for (Player player : room[i]) 
            cout << player.level << ' ' << player.name << '\n';
    }

    return 0;
}