#include <bits/stdc++.h>
const long N =  55;
using namespace std;

int n,m,res=0,aw=0;
int cs[5],aa=0;
char a[N][N];
string s;
int main()
{   //freopen("A.inp","r",stdin);
    scanf("%d %d" , &n,&m);
    for (int i=1; i<=n; i++){
        cin>>s;
        for (int j=1; j<=m; j++)
          a[i][j] = s[j-1];
    }
    res=0;
    for (int i=1; i<=n-1; i++)
        for (int j=1; j<=m-1; j++)
           {
            memset(cs,0,sizeof(cs));
            aa=0;
            for (int ii=0; ii<=1; ii++)
            for (int jj=0; jj<=1; jj++)
            {
            if ( a[i+ii][j+jj] == 'f' ) cs[1] = 1;
            if ( a[i+ii][j+jj] == 'a' ) cs[2] = 1;
            if ( a[i+ii][j+jj] == 'c' ) cs[3] = 1;
            if ( a[i+ii][j+jj] == 'e' ) cs[4] = 1;
            }
            for (int ii=1; ii<=4 ;ii++)  if ( cs[ii] == 1 ) ++aa;
            if ( aa == 4 ) ++aw;
           }
    printf("%d",aw);
    //cout<<kt(2,2);
}
