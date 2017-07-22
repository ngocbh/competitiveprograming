#include <bits/stdc++.h>


using namespace std;
int a1 ,b1, a2, b2, a3, b3;
int main()
{      // freopen("B.inp","r",stdin);
        cin >> a1 >> b1;
        cin >> a2 >> b2;
        cin >> a3 >> b3;
        if ( a2 + a3 <= a1 && max(b2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( a2 + b3 <= a1 && max(b2,a3) <= b1 ) { cout << "YES"; return 0; }
        if ( b2 + a3 <= a1 && max(a2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( max(a2,a3) <= a1 && b2 + b3 <= b1 ) { cout << "YES"; return 0; }
        swap(a1,b1);
        if ( a2 + a3 <= a1 && max(b2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( a2 + b3 <= a1 && max(b2,a3) <= b1 ) { cout << "YES"; return 0; }
        if ( b2 + a3 <= a1 && max(a2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( max(a2,a3) <= a1 && b2 + b3 <= b1 ) { cout << "YES"; return 0; }
        /*swap(a2,b2);
        if ( a2 + a3 <= a1 && max(b2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( a2 + b3 <= a1 && max(b2,a3) <= b1 ) { cout << "YES"; return 0; }
        if ( b2 + a3 <= a1 && max(a2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( max(a2,a3) <= a1 && b2 + b3 <= b1 ) { cout << "YES"; return 0; }
        swap(a3,b3);
        if ( a2 + a3 <= a1 && max(b2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( a2 + b3 <= a1 && max(b2,a3) <= b1 ) { cout << "YES"; return 0; }
        if ( b2 + a3 <= a1 && max(a2,b3) <= b1 ) { cout << "YES"; return 0; }
        if ( max(a2,a3) <= a1 && b2 + b3 <= b1 ) { cout << "YES"; return 0; }*/
        cout << "NO";
}
