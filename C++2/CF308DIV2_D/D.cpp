#include <bits/stdc++.h>
#define x first
#define y second
const long N = 2000 + 10;
using namespace std;
typedef pair <int,int> point;

int n,cs,res,rres,ccs;
float hsg[N][N],cc[N];
point a[N];

int main()
{   freopen("D.inp","r",stdin);
    scanf("%d ", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", &a[i].x, & a[i].y);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ( a[j].x - a[i].x !=0 )
                hsg[i][j] = (float) ( a[j].y - a[i].y ) / ( a[j].x - a[i].x );
            else hsg[i][j] = -10000000+7;
    for (int i = 1; i <= n-2; i++){ cs = 0; ccs = 1;
        for (int j = i; j <= n; j++) cc[++cs] = hsg[i][j];
        // for (int j = 1; j <= cs; j++) cout<<cc[j]<<" "; cout<<endl;
        sort(cc+1,cc+cs+1); cc[0] = -10000000+7;
       // for (int j = 1; j <= cs; j++) cout<<cc[j]<<" "; cout<<endl;
        rres = (n-i)*(n-i-1)/2;// cout<<rres<<"%";
        for (int j = 1; j <= cs; j++) {
            if ( cc[j] == cc[j-1] && cc[j] != -10000000+7 )  ++ccs;
            else ccs = 1;
            //cout<<ccs<<" ";
            rres = rres - ((ccs-1)*(ccs));
        }//cout<<rres<<"%";
        res += rres;
        cout<<res<<"*"<<endl;
    }
   // for (int i = 1; i <= n; i++){
   //     for (int j = 1; j <= n; j++) cout<<hsg[i][j]<<" "; cout<<endl;}
    cout<<res;
}
