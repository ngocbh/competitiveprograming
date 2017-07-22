#include <bits/stdc++.h>
#define fi cin
#define fo cout
using namespace std;
//ifstream fi("m00pair.inp");
//ofstream fo("m00pair.out");
string s;
char ntos(int n)
{
    return (char) (n+48);
}
int ston(char c)
{
    return (int) (c-'0');
}
void chuanhoa(string &a, string &b)
{  int l1,l2;
    l1=a.size(); l2=b.size();
    if (l1>l2) b.insert(0,l1-l2,'0');
    else a.insert(0,l2-l1,'0');
}
string sum(string a,string b)
{    string c;
    chuanhoa(a,b);
    int n,nho=0;
    n=a.size();
    for (int i=n-1; i>=0; i--){
        int cc;
        cc=ston(a[i])+ston(b[i])+nho;
        nho=cc/10;
        c=ntos(cc%10)+c;
    }
    if (nho==1) c="1"+c;
    return c;
}
int n,a[10000],maxn=0;
string f[10000],sl[10000];
int main()
{   int m=0;
    while (!fi.eof()){
        fi>>n;
       a[++m]=n;
        if (n>maxn) maxn=n;
    }
    f[1]="0"; sl[1]="2";
    f[2]="1"; sl[2]="4";
    f[3]="1"; sl[3]="8";
    for (int i=4; i<=maxn; i++){
        f[i]=sum(sl[i-3],f[i-2]);
        sl[i]=sum(sl[i-1],sl[i-1]);
    }
    for (int i=1; i<=m-1; i++)
        fo<<f[a[i]]<<endl;
}

