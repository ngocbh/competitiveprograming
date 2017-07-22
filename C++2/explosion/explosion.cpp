#include <bits/stdc++.h>

using namespace std;
//ifstream fi("explosion.inp");
//ofstream fo("explosion.out");
int n,m;
bool f[1000100],ok=false;
char s1[100],s[1000100];
int main()
{ freopen("explosion.inp","r",stdin);
  freopen("explosion.out","w",stdout);
  gets(s);
  gets(s1);
  n=strlen(s);
  m=strlen(s1);
  memset(f,true,sizeof(f));
  int i,j;
  i=0;
  while (i<=n ){
     if (!f[i]) { ++i; continue; }
     j=0;
     int dem=0,l,nho;
     l=i;
     while (j<=m-1)
     {
        if (!f[j+l]) { ++l; continue;}
        if (s[j+l]==s1[j]) {++dem; nho=j+l;}
        else break;
        ++j;
     }
    //==================
     if ( dem<m ) {++i; continue;}
     for (int j=i; j<=nho; j++) f[j]=false;
     i=i-m+1;

  }
  ok=false;
  for (int i=0; i<=n-1; i++) if (f[i]) ok=true;
  //printf("%d",ok);
  if (ok==false)printf("-1");
  for (int i=0; i<=n-1; i++)
     if (f[i]) {printf("%c",s[i]);}
 //printf("-1");

}
