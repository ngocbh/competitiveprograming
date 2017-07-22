#include <bits/stdc++.h>
//#include <cmath>
//#define fi cin
//#define fo cout
using namespace std;
//ifstream fi("dseq.inp");
//ofstream fo("dseq.out");
long long a[1000010],f[1000010],fj[1000010];
int n;
pair <long long ,long long> fm1[1000010],fm2[1000010];
int nhap()
{ //scanf("%d",&n);
cin>>n;
 for (int i=1; i<=n; ++i)
    //scanf("%I64d",&a[i]);
   cin>>a[i];
//return 0;

}
long long abs1(long long x)
{ if (x>=0) return x;
  else return -x;

}
void khoitao()
{ for (int i=1; i<=n; ++i) f[i]=f[i-1] + a[i];
  for (int j=n; j>=1; --j) fj[j]=fj[j+1]+a[j];
  for (int i=1; i<=n+1; ++i) {fm1[i].first=-1000000010;fm2[i].first=1000000010;}
  //====================
  for (int i=n; i>=1; --i)
  { if (fj[i]>fm1[i+1].first)
      { fm1[i].first=fj[i];
        fm1[i].second=1;
      }
    else
    { if (fj[i]==fm1[i+1].first)
        { fm1[i].first=fj[i];
        fm1[i].second=fm1[i+1].second +1;
        }
     else
        { fm1[i].first=fm1[i+1].first;
       fm1[i].second=fm1[i+1].second;

        }
    }
  }
  //===================
   for (int i=n; i>=1; --i)
  { if (fj[i]<fm2[i+1].first)
      { fm2[i].first=fj[i];
        fm2[i].second=1;
      }
    else
    { if (fj[i]==fm2[i+1].first)
        { fm2[i].first=fj[i];
        fm2[i].second=fm2[i+1].second +1;
        }
     else
        { fm2[i].first=fm2[i+1].first;
       fm2[i].second=fm2[i+1].second;

        }
    }
  }

}
void xuly()
 { long long maxn,dem,maxn1,dem1;
   int bcl=100000000;
   maxn=(long long)-bcl*bcl; maxn1=(long long)-bcl*bcl;
      for (int i=1; i<=n-1; ++i)
      { if  (abs1(f[i]-fm1[i+1].first)>maxn)
            { maxn=abs1(f[i]-fm1[i+1].first);
                dem=fm1[i+1].second;
            }
        else
            if ((abs1(f[i]-fm1[i+1].first)==maxn))
                dem=dem+fm1[i+1].second;
            //================
        if  (abs1(f[i]-fm2[i+1].first)>maxn1)
            { maxn1=abs1(f[i]-fm2[i+1].first);
                dem1=fm2[i+1].second;
            }
        else
            if ((abs1(f[i]-fm2[i+1].first)==maxn1))
                dem1=dem1+fm2[i+1].second;
      }
if (maxn1<maxn)
//printf("%I64d %I64d", maxn, dem);
 cout<<maxn<<" "<<dem;
 else
    //printf("%I64d %I64d", maxn1, dem1);
  cout<<maxn1<<" "<<dem1;
   //printf("%lld" ,a[1]);

 }
int main()
{ nhap();
 khoitao();
 //for (int i=1; i<=n; ++i) fo<<fmin[i].second<<" "; fo<<endl;
 xuly();

 return 0;
}

