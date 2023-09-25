#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, string> smap;

void set()
{
    smap["CU"] = "see you";
    smap[":-)"] = "I¡¯m happy";
    smap[":-("] = "I¡¯m unhappy";
    smap[";-)"] = "wink";
    smap[":-P"] = "stick out my tongue";
    smap["(~.~)"] = "sleepy";
    smap["TA"] = "totally awesome";
    smap["CCC"] = "Canadian Computing Competition";
    smap["CUZ"] = "because";
    smap["TY"] = "thank-you";
    smap["YW"] = "you¡¯re welcome";
    smap["TTYL"] = "talk to you later";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    set();

    while (true) {
        string s;
        cin >> s;

        if (smap.find(s) == smap.end()) 
            cout << s << "\n";
        else 
            cout << smap[s] << "\n";

        if (s == "TTYL") break;
    }

    return 0;
}