#include<bits/stdc++.h>

using namespace std;

ifstream fi("CLOCK.inp");
ofstream fo("CLOCK.out");

int hm[10][5][3]={{{1,1,1}, {1,0,1}, {1,0,1}, {1,0,1}, {1,1,1}},
                  {{0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
                  {{1,1,1}, {0,0,1}, {1,1,1}, {1,0,0}, {1,1,1}},
                  {{1,1,1}, {0,0,1}, {1,1,1}, {0,0,1}, {1,1,1}},
                  {{1,0,1}, {1,0,1}, {1,1,1}, {0,0,1}, {0,0,1}},
                  {{1,1,1}, {1,0,0}, {1,1,1}, {0,0,1}, {1,1,1}},
                  {{1,1,1}, {1,0,0}, {1,1,1}, {1,0,1}, {1,1,1}},
                  {{1,1,1}, {0,0,1}, {0,0,1}, {0,0,1}, {0,0,1}},
                  {{1,1,1}, {1,0,1}, {1,1,1}, {1,0,1}, {1,1,1}},
                  {{1,1,1}, {1,0,1}, {1,1,1}, {0,0,1}, {1,1,1}}};

char s;
int a[100][100];
bool kt;
int kq[6];

void xuli(int x)
{
    if (x==1)
        for (int i=0; i<=2; i++)
        {
            kt=true;
            for (int j=0; j<=4; j++)
                for (int k=0; k<=2; k++)
                    if (hm[i][j][k]==0 && a[j][k]==1) {kt=false; break;}
            if (kt) {kq[x]=i; break;}
        }
    if (x==3)
        for (int i=0; i<=5; i++)
        {
            kt=true;
            for (int j=0; j<=4; j++)
                for (int k=0; k<=2; k++)
                    if (hm[i][j][k]==0 && a[j][k+6]==1) {kt=false; break;}
            if (kt) {kq[x]=i; break;}
        }
    if (x==2)
        for (int i=0; i<=9; i++)
        {
            kt=true;
            for (int j=0; j<=4; j++)
                for (int k=0; k<=2; k++)
                    if (hm[i][j][k]==0 && a[j][k+3]==1) {kt=false; break;}
            if (kt) {kq[x]=i; break;}
        }
    if (x==4)
        for (int i=0; i<=9; i++)
        {
            kt=true;
            for (int j=0; j<=4; j++)
                for (int k=0; k<=2; k++)
                    if (hm[i][j][k]==0 && a[j][k+9]==1) {kt=false; break;}
            if (kt) {kq[x]=i; break;}
        }
}

int main()
{
    for (int i=0; i<=4; i++)
        for (int j=0; j<=11; j++)
    {
        fi>>s; if (s=='#') a[i][j]=1;
        else a[i][j]=0;
    }
    /*for (int i=1; i<=5; i++)
    {
        for (int j=1; j<=12; j++)
            fo<<a[i][j];
        fo<<endl;
    }*/
    for (int i=1; i<=4; i++)
    {
        xuli(i);
    }
    fo<<kq[1]<<kq[2]<<":"<<kq[3]<<kq[4];
       return 0;
}
