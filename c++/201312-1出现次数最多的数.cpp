#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main()
{
    int n, tmp;
    cin >> n;
    while (n--) {
        cin >> tmp;
        mp[tmp]++;
    }
    int ans = mp.begin()->first;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        if (mp[ans] < it->second) {
            ans = it->first;
        }
    }
    cout << ans << endl;
    return 0;
}

