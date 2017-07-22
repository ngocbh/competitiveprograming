#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;
int ns,nt;
char s[N], t[N];
int Tx, T[N];

void calc_T()
{
    for (int i = 1; i <= ns; i++) {
        if ( i < nt ) {
            T[i] = -1;
            continue;
        }
        bool ok = true;
        for (int j = 1; j <= nt; j++) {
            if ( t[j] == '*' ) continue;
            if ( t[j] == s[i-nt+j] ) continue;
            ok = false;
            break;
        }
        if ( ok == true ) T[i] = i-nt+1;
        else T[i] = -1;
    }
    for (int i = 1; i <= ns; i++) cout << T[i] << " "; cout << endl;
}

int main()
{   freopen("PATTMATC.inp","r",stdin);
    cin >> Tx;
    while ( Tx-- ) {
        scanf("%s", t+1); nt = strlen(t+1);
        scanf("%s", s+1); ns = strlen(s+1);
        calc_T();
    }

}
