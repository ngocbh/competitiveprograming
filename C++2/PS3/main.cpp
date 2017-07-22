#include <bits/stdc++.h>

using namespace std;

ifstream fi("PS3.inp");
ofstream fo("PS3.out");

typedef long long ll;
const int N=10000001;
ll M,t[N],t1[N],k[N],k1,sz;
string s;
bool e;

/*
void turnright()
{
    x= ( m1 + u ) % M, y = ( m2 + v ) % M;
    m1 = ( m1 + u ) % M;
    m2 = ( m2 + v ) % M;
}
`
void turnleft()
{
    u = ( m1 + x ) % M, v = ( m2 + y ) % M;
    m1 = ( m1 + x ) % M;
    m2 = ( m2 + y ) % M;
}
*/

void div2()
{
    int nho=0;
    memset(t1,0,N);
    e=true;
    for(int i=1; i<sz; i++)
    {
        nho=nho*10+(t[i]-'0');
        t1[i]=(nho/2)+'0';
        if(t1[i]!=0) e=false;
        nho%=2;
    }
    k[++k1]=nho;
    memset(t,0,s.size());

}

void pt()
{
    k1=0;
    while(!e)
        div2();
}

int main()
{
    fi>>s>>M;
    for(int i=0; i<s.size(); i++)
        t[i+1]=s[i];
    sz=s.size();
    pt();
    for(int i=1; i<=k1; i++)
        cout<<k[i];
    return 0;
}
