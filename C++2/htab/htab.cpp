#include <bits/stdc++.h>

using namespace std;

ifstream fi("htab.inp");
ofstream fo("htab.out");
const long maxn=70;

int a[maxn][maxn],b[maxn][maxn],m,n,k,res=0;
int f[maxn][maxn][maxn][maxn],l[maxn],r[maxn];
void timl1(int i,int j,int ii,int jj)
{   stack <int> s;
    s.push(0);
    for (int o=1; o<=j; o++) {
        while ( f[i][s.top()][ii][s.top()+jj-j] >= f[i][o][ii][o+jj-j] ) s.pop();
        l[o]=s.top();
        //if (l[i]==0) ++l[i];
        s.push(o);
    }
}
void timl2(int i,int j,int ii,int jj)
{   stack <int> s;
    s.push(0);
    for (int o=1; o<=jj; o++) {
        while ( f[i][s.top()+j-jj][ii][s.top()] >= f[i][o+j-jj][ii][o] ) s.pop();
        l[o]=s.top();
        //if (l[i]==0) ++l[i];
        s.push(o);
    }
}
void timr1(int i,int j,int ii,int jj)
{   stack <int> s;
    s.push(j+1);
    for (int o=j; o>=1; --o){
        while ( f[i][ s.top() ][ii][s.top()+jj-j] >= f[i][o][ii][o+jj-j] ) s.pop();
        r[o]=s.top();
        //if (r[i]==n+1) --r[i];
        s.push(o);
    }
}
void timr2(int i,int j,int ii,int jj)
{   stack <int> s;
    s.push(jj+1);
    for (int o=jj; o>=1; --o){
        while ( f[i][ s.top() +j-jj][ii][s.top()] >= f[i][o+j-jj][ii][o] ) s.pop();
        r[o]=s.top();
        //if (r[i]==n+1) --r[i];
        s.push(o);
    }
}
int main()
{  res=0;
   fi>>m>>n>>k;
   for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) fi>>a[i][j];
   for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) fi>>b[i][j];

   ///===================nhap;
   for (int i=1; i<=m;i++)

        for (int ii=1; ii<=m; ii++){
             ///===j<=jj;
             int jj=n;
             for (int j=n; j>=1; j--) {
                f[i][0][ii][jj-j]=f[i][j+1][ii][jj+1]=-1;
                for (int o=0; o<=j-1; ++o)
                    {if (abs(a[i][j-o]-b[ii][jj-o])<=k)  f[i][j-o][ii][jj-o]=f[i-1][j-o][ii-1][jj-o]+1;
                        else f[i][j-o][ii][jj-o]=0; ///cout<<f[i][j-o][ii][jj-o]<<" ";
                       }
                   /// cout<<endl<<i<<" "<<j<<" "<<ii<<" "<<jj<<endl;
               timl1(i,j,ii,jj);
               timr1(i,j,ii,jj);
               for (int o=1; o<=j; o++)
                if (f[i][o][ii][o+jj-j]!=0){
                    int rres;
                    rres=f[i][o][ii][o+jj-j]*(r[o]-l[o]-1);
                    ///cout<<rres<<endl;
                   // if (i==2 && j==6 && ii==2 && jj==7) cout<<rres<<" "<<f[i][o][ii][o+jj-j]<<" "<<r[o]<<" "<<l[o]<<" "<<endl;
                    if (rres>res) res=rres;
               }
            /*if (i==2 && j==6 && ii==2 && jj==7)
               {
                   for (int t=1; t<=j; t++) cout<<r[t]<<" "; cout<<endl;
                   for (int t=1; t<=j; t++) cout<<l[t]<<" "; cout<<endl;
                   for (int t=1; t<=j; t++) cout<<f[i][t][ii][t+jj-j]<<" "; cout<<endl;

                   //cout<<rres;
               }*/
             }
              ///===j>=jj;
             int j=n;
             for (int jj=n; jj>=1; jj--) {
                f[i][j-jj][ii][0]=f[i][j+1][ii][jj+1]=-1;
                for (int o=0; o<=jj-1; ++o)
                    {if (abs(a[i][j-o]-b[ii][jj-o])<=k)  f[i][j-o][ii][jj-o]=f[i-1][j-o][ii-1][jj-o]+1;
                        else f[i][j-o][ii][jj-o]=0; ///cout<<f[i][j-o][ii][jj-o]<<" ";
                        }
                         ///cout<<endl<<i<<" "<<j<<" "<<ii<<" "<<jj<<endl;

               timl2(i,j,ii,jj);
               timr2(i,j,ii,jj);

                 int rres;
               for (int o=1; o<=jj; o++)
                if (f[i][o+j-jj][ii][o]!=0){

                    rres=f[i][o+j-jj][ii][o]*(r[o]-l[o]-1);

                    if (rres>res) res=rres;
               }

             }
        }
fo<<res;
}
