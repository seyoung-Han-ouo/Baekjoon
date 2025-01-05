#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    while (N--) {
        int n, x;
        cin >> n;

        switch (n)
        {
        case 1:
            cin >> x;
            d.push_front(x);
            break;

        case 2:
            cin >> x;
            d.push_back(x);
            break;

        case 3:
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.front() << '\n';
                d.pop_front();
            }
            break;

        case 4:
            if (d.empty()) cout << "-1\n";
            else {
                cout << d.back() << '\n';
                d.pop_back();
            }
            break;

        case 5:
            cout << d.size() << '\n';
            break;

        case 6:
            cout << (int)d.empty() << '\n';
            break;

        case 7:
            cout << (d.empty() ? -1 : d.front()) << '\n';
            break;

        default:
            cout << (d.empty() ? -1 : d.back()) << '\n';
            break;
        }
    }

    return 0;
}