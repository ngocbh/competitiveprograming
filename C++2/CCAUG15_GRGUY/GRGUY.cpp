#include <bits/stdc++.h>

const long N = 1000000 + 10;
using namespace std;
char L1[N], L2[N];
int t, f1[N], f2[N], n;
int main()
{   //freopen("GRGUY.inp","r",stdin);
    scanf("%d", &t);
    while ( t-- ) {
        scanf("%s", L1+1);
        scanf("%s", L2+1);
        L1[0] = '.';
        L2[0] = '.';
        n = strlen(L1+1);
        int ans = 0;
        for (int i = 1; i <= n; i++) {
                f1[i] = N;
                f2[i] = N;
                if ( L1[i] == '.' ) {
                    f1[i] = min(f1[i],f1[i-1]);
                    f2[i] = min(f2[i],f1[i-1] + 1);
                    f2[i] = min(f2[i],f1[i]+1);
                }
                if ( L2[i] == '.' ) {
                    f1[i] = min(f1[i],f2[i-1]+1);
                    f2[i] = min(f2[i],f2[i-1]);
                    f1[i] = min(f1[i],f2[i] + 1) ;
                }
                if ( L1[i] == '#' && L2[i] == '#' ) {
                    ans = -1;
                    break;
                }
        }
        if ( ans == -1 ) {
                cout << "No" << endl;
                continue;
        }
        cout << "Yes" << endl << min(f1[n],f2[n]) << endl;

    }

}
