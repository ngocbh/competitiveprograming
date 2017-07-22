#include <bits/stdc++.h>
using namespace std;
ifstream fi("abcd.inp");
ofstream fo("abcd.out");
int res=0;
string a,b,c,d,t;
char ntos(int n)
{
    return (char) ( n+48 );
}
int ston(char c)
{
    return (int) (c-'0');
}
void chuanhoa(string &a,string &b)
{   string tg;
    int l1=a.length(),l2=b.length();
    if (l1>=l2)  b.insert(0,l1-l2,'0');
    else a.insert(0,l2-l1,'0');
    if (a<b) {tg=a; a=b; b=tg;}
}
string  sub(string a,string b)
{   string s="";
    int n;
    int nho=0;
    chuanhoa(a,b);
    n=a.size();
    for (int i=n-1; i>=0; i--){
        int c;
        c=ston(a[i])-ston(b[i])-nho;
        if (c<0) {c+=10; nho=1; } else nho=0;
        s.insert(0,1,ntos(c));
    }
    while (s[0]=='0')
        s.erase(0,1);
    if (s=="") return "0";

    return s;
}
int main()
{  fi>>a;
   fi>>b;
   fi>>c;
   fi>>d;
    //fo<<sub(a,b)<<endl;

   while (1==1){
        t=a;
        //fo<<" ^^^"<<endl;
        if (a=="0" && b=="0" && c=="0" && d=="0") break;
        if (res>1000000) { fo<<-1; return 0; }
        a=sub(a,b); //fo<<a<<endl;
        b=sub(b,c); //fo<<b<<endl;
        c=sub(c,d); //fo<<c<<endl;
        d=sub(d,t); //fo<<d<<endl;
        ++res;
       // fo<<"%%";
   }
   fo<<res<<endl;

}
