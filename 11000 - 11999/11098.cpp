#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    while (n--) {
        int p;
        cin >> p;

        int mxC = 0;
        string result = "";

        for (int i = 0; i < p; i++) {
            int c;
            string n;

            cin >> c >> n;

            if (c > mxC) {
                mxC = c;
                result = n;
            }
        }

        cout << result << '\n';
    }

    return 0;
}