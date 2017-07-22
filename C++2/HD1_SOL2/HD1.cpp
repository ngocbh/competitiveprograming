#include <bits/stdc++.h>

const long N = 2000 + 10;
using namespace std;

int n, k1, k2;
char a[N], b[N], s[N];

int main()
{   freopen("HD1.inp","r",stdin);
    freopen("HD1.out","w",stdout);

    cin >> k1 >> k2;
    scanf("%s", a+1);
    scanf("%s", b+1);
    n = strlen(a+1);

    int x, y, v = 0;
    for (int i = 1; i <= n; i++)
        if ( a[i] != b[i] ) ++v;

    x = (k1+k2-v)/2;
    y = (k1+v-k2)/2;

    for (int i = 1; i <= n; i++) {
        if ( a[i] == b[i] ) {
            if ( x > 0 )
                s[i] = '0'+'1'-a[i], --x;
            else
                s[i] = a[i];
        }
    }

    for (int i = 1; i <= n; i++)
        if ( a[i] != b[i] ) {
            if ( y > 0 )
                s[i] = b[i],--y;
            else
                s[i] = a[i];
        }

    for (int i = 1; i <= n; i++) cout << s[i];
}
