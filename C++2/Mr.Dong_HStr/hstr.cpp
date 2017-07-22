#include <bits/stdc++.h>

using namespace std;
ifstream fi("hstr.inp");
ofstream fo("hstr.out");
const long maxn = 3000+200;
const long long cc=10000000000000;

int k,n,f1[maxn][maxn],f2[maxn][maxn],f[maxn][maxn];
string s,s1,s2;
void khoitao()
{
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++){
            if (i==j) f1[i][j]=s[j-1]-'a';
            else f1[i][j]=(f1[i][j-1]*26000+s[j-1]-'a') %cc;
    }
    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++){
            if (i==j) f2[i][j]=s1[j-1]-'a';
            else f2[i][j]=(f2[i][j-1]*26000+s1[j-1]-'a') %cc;
    }
}
int kiemtra(int x,int y)
{   int dem=0;
    ///===123;
    if (f1[1][x]==f2[1][x] && f1[x+1][y]==f2[x+1][y] && f1[y+1][n]==f2[y+1][n]) ++dem;
    ///====321;
    if (f1[y+1][n]==f2[1][n-y] && f1[x+1][y]==f2[n-y+1][n-x] && f1[1][x]==f2[n-x+1][n]) ++dem;
    ///===312;
    if (f1[y+1][n]==f2[1][n-y] && f1[1][x]==f2[n-y+1][n-y+1+x-1] && f1[x+1][y]==f2[n-y+x+1][n]) ++dem;
    ///===213;
    if (f1[x+1][y]==f2[1][y-x] && f1[1][x]==f2[y-x+1][y-x+1+x-1] && f1[y+1][n]==f2[y+1][n])++dem;
    ///===231;
    if (f1[x+1][y]==f2[1][y-x] && f1[y+1][n]==f2[y-x+1][y-x+1+n-y-1] && f1[1][x]==f2[n-x+1][n]) ++dem;
    ///===132;
    if (f1[1][x]==f2[1][x] && f1[y+1][n]==f2[x+1][x+1+n-y-1] && f1[x+1][y]==f2[n-y+x+1][n]) ++dem;
    return dem;

}
void xuly1()
{   int res=0;
   khoitao();
    for (int i=1; i<=n-2; i++)
        for (int j=i+1; j<=n-1; j++){
            if (i==1 && j==n) break;
            //if (i==1 && j==2) break;
            //if (i==(n-1) && j==n) break;
            if  (kiemtra(i,j)>0) res++;
          //cout<<kiemtra(i,j)<<" "<<i<<" "<<j<<endl;

    }
    fo<<res;
}
void khoitao2()
{
    memset(f,0,sizeof(f));
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
        if (abs(s[i-1]-s1[j-1])<=k) {f[i][j]=f[i-1][j-1]+1;      }
    //================
}
bool kiemtra1(int x,int y)
{
    ///===123;
    if (f[x][x]>=x && f[y][y] >=(y-x) && f[n][n]>=(n-y) ) return true;
    ///===321;
    if ( f[n][n-y ]>= (n-y) && f[y][n-y+y-x]>=(y-x) && f[x][n]>=x ) return true;
    ///===132;
    if (f[x][x]>=x && f[n][x+n-y]>=(n-y) && f[y][n]>=(y-x)  ) return true;
    ///===231;
    if (f[y][y-x]>=(y-x) && f[n][y-x+n-y]>=(n-y) && f[x][n]>=x  ) return true;
    ///===213;
    if (f[y][y-x]>=(y-x) && f[x][y-x+x]>=x && f[n][n]>=(n-y)  ) return true;
    ///===312;
    if (f[n][n-y]>=(n-y) && f[x][n-y+x]>=x && f[y][n]>=(y-x) ) return true;

    return false;
}
void xuly2()
{    int64_t res=0;
    khoitao2();
    for (int i=1; i<=n-2; i++)
        for (int j=i+1; j<=n-1; j++)
          if (kiemtra1(i,j)) {res++;}
    fo<<res;
   // for (int i=1; i<=n; i++ ) {
      //  for (int j=1; j<=n; j++) cout<<f[i][j]<<" "; cout<<endl; }
}
int main()
{  fi>>k;
   fi>>s; n=s.size();
   fi>>s1;
   // if (k==0) xuly1(); ///== co the goi luon xu ly 2. nhung cu de day' de? hieu?
   // else
        xuly2();
   //cout<<f1[4][6]<<" "<<f2[4][6];
}
