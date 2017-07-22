#include <bits/stdc++.h>
const long N = 10;

using namespace std;
int t, n, n2;
string A, B;
int main()
{
   // freopen("TWOSTR.inp","r",stdin);
    cin >> t;
    while ( t-- ) {
        cin >> A >> B;
        n = A.size();
        n2 = B.size();
        bool ok = true;
        if ( n != n2 ) ok = false;
        else
        for (int i = 0; i < n; i++)
            if ( A[i] != '?' && B[i] != '?' && A[i] != B[i] ) ok = false;
        if ( ok ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
