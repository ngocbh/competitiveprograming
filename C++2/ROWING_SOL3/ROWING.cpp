/*
    * CODE BY NGOCJR7
    * ALG of : Mr HOANG
    * DPT O(n*n)
    * ALG : tim tat ca cac con duong tu 0 den n+1.
            voi moi con duong chon khoang cac lon nhat giua 2 dinh de di qua.
            kq la min cua tat ca cac khoang can di qua.
            ta co  the lam = dijkstra de tim duong di ngan nhat tu 0 -> n+1
            voi d[i] la duong di ngan nhat tu 0 den i.
            thay tong do dai con duong bang do dai max giua cac con duong truc tiep tu 0 -> i
            toi uu bang cong thuc d[i] = min(d[i],max(du,kc(u,i));
*/

#include <bits/stdc++.h>
#define x first
#define y second
const long N = 4*1000 + 10;
const long oo = 1000000000 + 7;
const long MOD = 1000000000 + 7;

using namespace std;
typedef long long LL;
typedef pair <LL,int> ii;

int n, h;
LL d[N];
ii P[N];

LL kc(int i, int j)
{
    if ( i == 0 ) return 1LL*P[j].y*P[j].y;
    if ( j == 0 ) return 1LL*P[i].y*P[i].y;
    if ( i == n+1 ) return 1LL*(h-P[j].y)*(h-P[j].y);
    if ( j == n+1 ) return 1LL*(h-P[i].y)*(h-P[i].y);

    return 1LL*(P[i].x - P[j].x)*(P[i].x - P[j].x) + 1LL*(P[i].y - P[j].y)*(P[i].y - P[j].y);
}

void dijkstra()
{
    priority_queue <ii,vector<ii>, greater<ii> > qu;
    for (int i = 1; i <= n+1; i++) d[i] = 1LL*oo*oo;
    d[0] = 0;
    qu.push(ii(0,1));


    while ( !qu.empty() ) {
        LL u, du;
        u = qu.top().second;
        du = qu.top().first;
        qu.pop();

        for (int i = 1; i <= n; i++) {
            if ( d[i] > max(du,kc(u,i)) ) {
                d[i] = max(du,kc(u,i));
                qu.push(ii(d[i],i));
            }
        }
    }

}

int main()
{   freopen("ROWING.inp","r",stdin);
    freopen("ROWING.out","w",stdout);
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
        cin >> P[i].x >> P[i].y;

    dijkstra();

    cout << (LL) sqrt(d[n]);
}
