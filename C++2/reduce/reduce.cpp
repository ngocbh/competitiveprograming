#include <bits/stdc++.h>

using namespace std;
ifstream fi("reduce.inp");
ofstream fo("reduce.out");
int n,v,ta[210],a[210];
pair <int,int> ca[210];
bool f[210][90000],ok;
void nhap()
{  fi>>n>>v;
  for (int i=1; i<=n; ++i)
    fi>>a[i];
}
void khoitao()
{  memset(f,false,sizeof(f));
   //f[0][0]=true;
  // for (int i=1; i<=16; ++i) fo<<f[5][i]<<" ";
  // if (f[5][16]==false) fo<<1 ;
  // fo<<1;
 for (int i=0; i<=200; i++) ta[i]=2;
 f[1][a[1]+40000]=true;
 f[1][-a[1]+40000]=true;
}
void qhd()
{ khoitao();
  for (int i=2; i<=n; i++)
    for (int j=-20000; j<=20000;++j)
   {  if (f[i-1][j+a[i]+40000]) f[i][j+40000]=true;                                                                ///f[i][j+40000]=f[i-1][j+a[i]+40000];
      if (f[i-1][j-a[i]+40000]) f[i][j+40000]=true;
   }

}
void truyvet()
{ ok=false;
    if (f[n][v+40000]==true)
    { ok=true; //int m;m=n-1;
          for (int i=n; i>=1; i--)
            {   if (f[i-1][v-a[i]+40000]==true ) { ta[i]=1; v=v-a[i]; }
                else
                if (f[i-1][v+a[i]+40000]==true ) { ta[i]=0; v=v+a[i]; }
              if (i==1)
                if (v==a[1]) ta[1]=1;
                else ta[1]=0;
            }

    }

}
void xuly()
{   for (int i=1; i<=n; i++)
     {  ca[i].first=ta[i];
        ca[i].second=i;
     }
    //=========================
   // for (int i=1; i<=n; i++)
   int i=0,m;
   m=n;
   while (i<=n)
   { ++i;
     if (ca[i].first=1 && ca[i+1].first==0)
        {  int j,de; j=i+1;
            while ( ca[j]=0) {fo<<ca[i].second; ++j;}



        }
   }

}
int main()
{ nhap();
  khoitao();
  qhd();
  truyvet();
  xuly();
 //if (f[n-2][18+40000])  fo<<n;
//fo<<ok<<endl;
 //  for (int i=1; i<=n; ++i) fo<<ta[i]<<" "; fo<<endl;
   //for (int j=39970; j<=40030; ++j){ for (int i=1; i<=n; ++i)fo<<f[i][j]<<" ";fo<<endl;}

}
