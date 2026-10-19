#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl '\n'

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    i64 a, b, c;
    cin >> a >> b >> c;

    string x1 = "1" + string(a + b - 1, '0');
    string y1 = "1" + string(b - 1, '9') + string(a, '0');
    string x2 = "1" + string(a - 1, '0') + string(b, '9');
    string y2 = "1" + string(a + b - 1, '9');

    cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;

}	