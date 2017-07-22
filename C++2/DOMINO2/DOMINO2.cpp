#include <bits/stdc++.h>
#define x first
#define y second
const long N = 30;
using namespace std;
typedef pair <int,int> ii;
int n,ca[7][7][7][7],res;
ii a[N],x[N];
vector <int> aa[7];

void duyet(int ii)
{   int v;
    for (int i = 0; i <= aa[c].size()-1; i++){
        v = aa[c][i];
        if ( ca[x[ii-1].x][x[ii-1].y][a[v].x][a[v].y] ) {
            x[ii].x = a[v].x; x[ii].y = a[v].y;
            ca[x[ii-1].x][x[ii-1].y][a[v].x][a[v].y] = false;
            ca[a[v].x][a[v].y][x[ii-1].x][x[ii-1].y] = false;
            duyet(ii+1);

        }
    }
}
int main()
{   freopen("DOMINO2.inp","r",stdin);
    cin>>n;
    for (int i = 1; i <= n; i++) {
        cin>>a[i].x>>a[i].y;
        aa[a[i].x].push_back(i);
        aa[a[i].y].push_back(i);
    }

}
