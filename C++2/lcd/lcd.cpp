#include <iostream>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#include <vector>
#include <queue>
#include <string>
#define maxn 1000000
using namespace std;
int n,ta[maxn],tt[10],tb[maxn],kq[maxn];
bool ok=false;
string s;
int xsn( char c )
{
    return ( int ) ( c - '0' );
}
void truyvet(int u)
{   int res=0;
    while ( ta[u] != -1 ){
            kq[++res]=tb[u];
            u=ta[u];
    }
      cout<<u;
    for (int i=res; i>=1; i--) printf("%d",kq[i]);

}
void bfs()
{   queue <int> qu;
    for (int i=1; i<=10; i++ )
       if ( tt[i] ) {
                int c;
                c=i % n;
                ta[i]=-1;
                tb[i]=c;
                qu.push( i );
       }
    ///===============
    while ( ! qu.empty() ) {
        if ( ok ) break;
        int u;
        u=qu.front();
        qu.pop();
        for (int i=0; i<=10; i++)
            if ( tt[i]==1 ){
                int c;
                c = (u*10 + i) % n;
                if ( ta[c] ) continue;
                ta[c] = u;
                tb[c]=i;
                if ( c == 0 ) { truyvet(c); ok=true; break; }
                qu.push(c);
            }

    }
    if ( !ok ) cout<<0;
}
int main()
{   freopen("lcd.inp","r",stdin);
    freopen("lcd.out","w",stdout);
    cin >> n;
    cin >> s;
    for (int i=0; i<=s.size(); i++ ) tt[xsn( s[i] )] = 1;
    bfs();
}
