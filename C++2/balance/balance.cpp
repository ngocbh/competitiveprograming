#include <bits/stdc++.h>

using namespace std;
ifstream fi("balance.inp");
ofstream fo("balance.out");
int n,m;
string f[2][6000];
int stringtonum(char c)
{
    return (int) (c - '0');
}
char numtostring(int n)
{
    return (char) (n+48);
}
void chuanhoa(string &a, string &b)
{
    int l1=a.length(),l2=b.length();
    if (l1>=l2)  b.insert(0,l1-l2,'0');
    else a.insert(0,l2-l1,'0');


}
string sum(string a,string b)
{
   string s="";
   chuanhoa(a,b);
   int l=a.length();
   int temp = 0;
   for (int i=l-1; i>=0; i--)
   {
      temp =stringtonum(a[i])+stringtonum(b[i])+temp;
      s.insert(0,1,numtostring(temp%10));
      temp=temp/10;
   }
   if (temp>0)
   {
       s.insert(0,1,numtostring(temp));
   }
   return s;
}
int abs1(int x)
{ if (x>0) return x;
  else return -x;

}
int main()
{ fi>>n>>m;
 int maxj = (n + 1 ) * n / 2;
f[0][0]="1";
for (int i=1; i<=maxj; i++) f[0][i]="0";
int i;
 i=0;
  for (int l=1; l<=n; l++)
  { i=1-i;
    for (int j=0;j<=maxj; j++)
     {
         f[i][j] = "0";
      /*if (i==j)
      { f[i][j]=sum(f[i-1][j],sum("1",f[i-1][2*i]))  ;                              ///f[i-1][j]+1+f[i-1][2*i];
        string h="0";
        for (int k=i-2; k>1; --k)
          h=sum(h,sum(f[k][k+1],f[k][k+1]));                                                     ///h+f[k][k+1]*2;
        //fo<<h<<endl;
        f[i][j]= sum(f[i][j],h)  ;                                                  ///f[i][j]+h;

      }
      else
      {*/

       f[i][j]=sum(f[1-i][j],sum(f[1-i][j+l],f[1-i][abs1(j-l)]))    ;                   ///f[i-1][j]+f[i-1][j+i]+f[i-1][abs1(j-i)];
      // if ((i==6)&&(j==1))
         //fo<<f[i-1][j]<<" "<<f[i-1][j+i]<<" "<<f[5][5];
      }//if(i==19) fo<<f[i][j]<<endl;

      }
    fo<<f[i][m];


   // string a;
   // a=sum("2343841535346","548351315354");
   // for (int i=0; i<=15;++i) fo<<a[i];
}
