#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#define maxn 1000+100

using namespace std;
int a[maxn][maxn],h[maxn][maxn],l[maxn],r[maxn],res=0,n,m;

void timl(int x)
{   stack <int> s;
    s.push(0);
    for (int i=1; i<=m; i++) {
        while ( h[x][s.top()] >= h[x][i] ) s.pop();
        l[i]=s.top();
        s.push(i);
    }
}
void timr(int x)
{   stack <int> s;
s.push(m+1);
    for (int i=m; i>=1; i--){
        while ( h[x][s.top()] >= h[x][i] ) s.pop();
        r[i]=s.top();
        s.push(i);
    }
}
int main()
{   //freopen("qbrect.inp","r",stdin);
    //freopen("qbrect.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++) scanf("%d",&a[i][j]);

    for (int i=1; i<=n; i++ ){
        for (int j=1; j<=m; j++)
            if (a[i][j]==1) h[i][j]=h[i-1][j]+1;
            else h[i][j]=0;
        h[i][0]=h[i][m+1]=-1;
       // for (int j=1; j<=m; j++) cout<<h[i][j]<<" "; cout<<endl;
        ///=====
        timl(i);
        timr(i);
        for (int j=1; j<=m; j++){
            int rres;
            rres=h[i][j] * (r[j]-l[j]-1);
           // cout<<l[i]<<" "<<r[i]<<" "<<h[i][j]<<" ";
            if (rres>res) res=rres;
        }
       // cout<<endl;
    }
    printf("%d",res);

}

