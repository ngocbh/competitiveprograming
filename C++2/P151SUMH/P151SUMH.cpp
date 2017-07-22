#include <bits/stdc++.h>
///Bai G
const long N = 100000 + 10;
using namespace std;
int n, m, a[2*N], t, cs[2*N];
char s1[N], s2[N];

bool cmp(int i, int j)
{
    return a[i] < a[j];
}
int main()
{   freopen("P151SUMH.inp","r",stdin);
    scanf("%d %d", &n, &m);
    scanf("%s", &s1);
    scanf("%s", &s2);
    scanf("%d", &t);
    int cc = 1;;
    for (int i = n; i >= 1; i--) {
            a[i] = cc;
            cc += 2;
            cs[i]  = i;
    } --cc;
    for (int i = n+1; i <= n+m; i++) {
            a[i] = cc;
            cc += 2;
            cs[i] = i;
    }
    for (int i = 1; i <= n; i++) a[i] += 2*t;
    sort(cs + 1, cs + n + m + 1, cmp);
    for (int i = 1; i <= n + m; i++)
        if ( cs[i] <= n )
            printf("%c", s1[cs[i]-1]);
        else
            printf("%c", s2[cs[i] - n -1]);
}
