#include <bits/stdc++.h>

using namespace std;
int t, s;
int main()
{
    cin >> t;
    cin >> s;
    if ( t == 0 ) {
        for  (int i = 1; i <= s; i++) cout << 1 << endl;
    }
    if ( t == 1 ) {
            for (int i = 1; i <= s; i++) cout << 2 << endl;
    }
    if ( t == 2 ) {
        for (int i = 1; i <= s; i++) cout << 0 << endl;
    }
}
