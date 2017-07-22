#include <bits/stdc++.h>

using namespace std;
ifstream fi("ACStr.inp");
ofstream fo("ACStr.out");
const long maxn1=1000+10;
const long maxk=100+100;
int m,n,k,ca[27][maxk],kq[maxk];
typedef pair<int,int> p2;
pair <int,p2>f[maxk];
string s,a[maxn1];
void xuly(int x)
{    int n1;
    n1=a[x].size();
    for (int i=0; i<=n-1; i++){
        int i1,i2;
        i1=(int) s[i]-'a'+1;
        ++ca[i1][i%n1];
    }
    for (int i=1; i<=n1; i++){
        int mm=0;
        for (int j=1; j<=27; j++)
            if (ca[j][i]>mm) {
                f[i].first=ca[j][i];
                f[i].second.first=j;
                f[i].second.second=i;
            }
    }
   // sort(f,f+n1,greater<int>() );
    //=======================
    memset(kq,0,sizeof(kq));
    for (int i=1; i<=k; i++)
        kq[f[i].second.second]=f[i].second.first;
    for (int i=1; i<=n1; i++)
        if (kq[i]==0) kq[i]=(a[x][i-1]-'a'+1);
   // fo<<a[x][1]<<endl;
    for (int i=1; i<=n1; i++)
         fo<<(char) (kq[i]+'a'-1);



}
int main()
{   fi>>m>>k;
    fi>>s; n=s.size();
    for (int i=1; i<=m; i++) fi>>a[i];
    for (int i=1; i<=m; i++) xuly(i);

}
