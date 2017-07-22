#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <memory.h>
#define maxn 1000+10
using namespace std;
int n,q;
string a[maxn],s1,s2;
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
string  sub(string a,string b);
string sum(string a,string b)
{  if ( a[0]!='-' && b[0]=='-' ) { b.erase(0,1); return sub( a,b ); }
   if ( a[0]=='-' && b[0]!='-' ) { a.erase(0,1);  return sub( b,a ); }
    int nho=0;
   if ( a[0]=='0' && b[0]=='0' ) { nho=1; a.erase(0,1); b.erase(0,1); }
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
   s='-'+s;
   return s;
}
string  sub(string a,string b)
{   if ( a[0]=='-' && b[0]!='-' ){ string s=""; a.erase(0,1); s=sum(a,b); s='-'+s; return s;  }
    if ( a[0]!='-' && b[0]=='-' ) { b.erase(0,1); return sum(a,b); }
    if ( a[0]=='-' && b[0]=='-' ) { a.erase(0,1); b.erase(0,1); return sub(b,a); }
    string s="";
    int n;
    int nho=0;
    if ( a < b ) { s=sub(b,a); s='-'+s; return s; }
    chuanhoa(a,b);
    n=a.size();
    for (int i=n-1; i>=0; i--){
        int c;
        c=stringtonum(a[i])-stringtonum(b[i])-nho;
        if (c<0) {c+=10; nho=1; } else nho=0;
        s.insert(0,1,numtostring(c));
    }
    while (s[0]=='0')
        s.erase(0,1);
    if (s=="") return "0";

    return s;
}
string nhanNho(char a, string b)
{
    string s = "";
    int temp = 0;
    for (int i=b.length()-1; i>=0; i--)
    {
        temp = stringtonum(a) * stringtonum(b[i]) + temp;
        s.insert(0,1,numtostring(temp%10));
        temp = temp/10;
    }

    if (temp>0)
    {
        s.insert(0,1,numtostring(temp));
    }
    return s;
}

string area(string a, string b)     // nhan 2 so lon
{   int nho=0;
    if ( (a[0]=='-' && b[0]!='-') || ( a[0]!='-' && b[0]=='-' ) )  nho=1;
    if ( a[0]=='-' ) a.erase(0,1);
    if ( b[0]=='-' ) a.erase(1,0);
    string s = "";
    int l = a.length();
    string s1[l];

    for (int i=l-1; i>=0; i--)   // nhan tung chu so cua a voi b sau do cong don vao
    {
        s1[i] = nhanNho(a[i], b);   // nhan tung so cua a voi b
        s1[i].insert(s1[i].length(), l-i-1, '0');
        s = sum(s, s1[i]);  // cong don theo cach cong so lon
    }
    if ( nho==1 ) s='-'+s;
    return s;
}
int main()
{   freopen("VOBIGNUM.inp","r",stdin);
    freopen("VOBIGNUM.out","w",stdout);
    cin>>n>>q;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=q; i++) {
        int i1,j1,i2,j2;
        char c1,c2;

        cin>>i1>>j1>>c1>>i2>>j2>>c2;
        ++i1; ++j1; ++i2; ++j2;
        if ( c1=='+' ) s1=sum(a[i1],a[j1]);
        if ( c1=='-' ) s1=sub(a[i1],a[j1]);
        if ( c1=='*' ) s1=area(a[i1],a[j1]);
        if ( c2=='+' ) s2=sum(a[i2],a[j2]);
        if ( c2=='-' ) s2=sub(a[i2],a[j2]);
        if ( c2=='*' ) s2=area(a[i2],a[j2]);
        if ( s1==s2 ) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

}
