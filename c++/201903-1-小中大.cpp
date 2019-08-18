#include <iostream>
#include <cstdio>

using namespace std;

int a[100001];

int main() {
    int n;
    int _min, _max, c, d;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (a[0] < a[1]) { //递增
        _min = a[0];
        _max = a[n-1];
        c = a[n/2-1];
        d = a[n/2];
    } else {          //递减
        _min = a[n-1];
        _max = a[0];
        c = a[n/2];
        d = a[n/2-1];
    }
    if (n & 1) {
        cout << _max << " " << a[(n+1)/2 - 1] << " " << _min << endl;
    } else {
        long long tmp = c + d;
        //小心求平均值的时候可能会溢出
        if (tmp & 1) {
            printf("%d %.1f %d\n", _max, d - (d - c) / 2.0, _min);
        } else {
            cout << _max << " " << d - (d - c) / 2 << " " << _min << endl;
        }
        
    }
    return 0;
}