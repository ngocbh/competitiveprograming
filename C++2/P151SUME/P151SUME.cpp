#include <bits/stdc++.h>

const long N = 4*100000 + 10;
using namespace std;

int n;
int a[N], l[N], r[N], b[N], ans[N], cs[N];

void search_l()
{
    stack <int> s;
    s.push(0);
    for (int i = 1; i <= n; i++){
        while ( a[s.top()] >= a[i] ) s.pop();
        l[i] = s.top();
        s.push(i);
    }
}

void search_r()
{
    stack <int> s;
    s.push(n+1);
    for (int i = n; i >= 1; i--){
        while ( a[s.top()] >= a[i] ) s.pop();
        r[i] = s.top();
        s.push(i);
    }
}

bool cmp(int i,int j)
{
    return a[i] < a[j];
}

int main()
{   //freopen("P151SUME.inp","r",stdin);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        cs[i] = i;
        b[i] = a[i];
    }
    sort(cs + 1, cs + n + 1, cmp );
    sort(b + 1, b + n + 1);
    a[0] = -1; a[n+1] = -1;
    search_l();
    search_r();
    int ii=n,ij;
    for (int i = n; i >= 1; i--){
            ij = ii;
            for (int j = 1; j <= (r[cs[i]] - l[cs[i]] - 1 - ( n - ij )); j++) {
                    ans[ii] = b[i];
                    --ii;
            }
    }

   for (int i = n; i >= 1; i-- ) printf("%d " , ans[i]);
}
