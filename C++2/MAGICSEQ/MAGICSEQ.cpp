#include <bits/stdc++.h>

const long N = 100000 + 10;
using namespace std;

int n;
int a[N], h[N];
char s[N];
int main()
{   freopen("MAGICSEQ.inp","r",stdin);
    freopen("MAGICSEQ.out","w",stdout);
    scanf("%s", s + 1);
    int n = strlen(s+1) + 1;
    s[n] = s[n-1];
    int _min = 1, _max = 1;
    a[1] = 1; h[1] = 1;
    for (int i = 2; i <= n; i++) {
        if ( s[i] == s[i-1] && s[i] == '<' ) a[i] = a[i-1] + 1;
        if ( s[i] != s[i-1] && s[i] == '<' ) a[i] = a[i-1] - 1;
        if ( s[i] != s[i-1] && s[i-1] == '<' ) a[i] = a[i-1] + 1;
        if ( s[i] == s[i-1] && s[i-1] == '>' ) a[i] = a[i-1] - 1;
    }

    int cur = 0;
    a[n+1] = n+1;
    for (int i = 2; i <= n+1; i++) {
        if ( a[i] > a[i-1] && a[i] > a[i+1] ) {
            for (int j = cur+1; j <= i-1; j++) h[j] = a[j] + cur + 1 - a[cur + 1];
            cur = i-1;
        }
        if ( a[i] < a[i-1] && a[i] < a[i+1] ) {
            for (int j = cur + 1; j <= i; j++) h[j] = a[j] +  cur + 1 - a[i];
            cur = i;
        }
    }
    for (int i = 1; i <= n; i++) printf("%d ", h[i]);
}
