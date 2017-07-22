#include <bits/stdc++.h>

const long N = 1000000+10;
using namespace std;
char s[N];
int n,cl,cr;
int cs[N],a[N];
int main()
{   //freopen("P151SUMA.inp","r",stdin);
    scanf("%s", &s);    n = strlen(s); cr = 1; cl= n;
    for (int i = 0; i < n; i++){
        if ( s[i] == 'l' ) {
            a[i] = cl;
            --cl;
        } else {
            a[i] = cr;
            ++cr;
        }
    }
    for (int i = 0; i < n; i++) cs[a[i]] = i+1;
    for (int i = 1; i <= n; i++) printf("%d ", cs[i]);

}
