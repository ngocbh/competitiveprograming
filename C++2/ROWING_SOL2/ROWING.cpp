/*
    * CODE BY NGOCJR7
    * ALG of : Mr Hoang
    * DPT O(n*n*log(n*n)) do sort;
    * ALG : sap xep theo do dai cac canh.
      them lan luot tung canh tu nho den lon.
      den khi nao di dc tu dinh 0 den dinh n+1 thi lay kq;
*/

#include <bits/stdc++.h>
#define x first
#define y second

const long N = 100000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef pair <int,int> ii;
typedef long long LL;
struct data{
    LL val, i, j;
};
int n, h;
int lad[N];
ii P[N];
data d[N];

LL kc(ii A,ii B)
{
    return 1LL*(A.x - B.x)*(A.x - B.x) + 1LL*(A.y - B.y)*(A.y - B.y);
}

int findroot(int u)
{
    if ( lad[u] < 0 ) return u;
    int r = findroot(lad[u]);
    lad[u] = r;
    return r;
}

void _union(int s,int r)
{
    int x = lad[s] + lad[r];
    if ( lad[s] < lad[r] ) {
        lad[r] = s;
        lad[s] = x;
    }
    else {
        lad[s] = r;
        lad[r] = x;
    }
}

bool cmp(data A,data B)
{
    return A.val < B.val;
}

int main()
{   freopen("ROWING.inp","r",stdin);
    freopen("ROWING.out","w",stdout);
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
        cin >> P[i].x >> P[i].y;

    int m = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i+1; j <= n; j++)
            d[++m] = data{kc(P[i],P[j]),i,j};

    for (int i = 1; i <= n; i++) {
        d[++m] = data{1LL*P[i].y*P[i].y,0,i};
        d[++m] = data{1LL*(h-P[i].y)*(h-P[i].y),i,n+1};
    }
    sort(d+1,d+m+1,cmp);

    for (int i = 0; i <= n+1; i++) lad[i] = -1;

    for (int i = 1; i <= m; i++) {
        int u = d[i].i, v = d[i].j;
        int r, s;
        r = findroot(u);
        s = findroot(v);
        if ( r != s ) {
            _union(r,s);
        }
        if ( findroot(0) == findroot(n+1) ) {
            cout << (LL) sqrt(d[i].val);
            return 0;
        }
    }
}
