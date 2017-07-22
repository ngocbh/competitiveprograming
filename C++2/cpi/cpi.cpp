#include <fstream>
#include <iomanip>

using namespace std;
ifstream fi("cpi.inp");
ofstream fo("cpi.out");
const long maxn=100000+100;
int n,p,b[4*maxn],c[4*maxn],nb,l,r,xx,k,q;
void update_t(int64_t y,int64_t z)
{
    int64_t t;
    while (y!=1){
        t=y/2; b[t]+=z; y=t;
    }
}
void xuly2()
{   fi>>l>>r>>xx;
    //fo<<l<<" "<<r<<" "<<xx;
    //for (int i=1; i<=4*n; i++) fo<<b[i]<<" ";fo<<endl;
    int fu=0,fv=0,u=nb+l-1,v=nb+r-1,k=1;
    while ( u!=v){
        if ((u&1) && !fu) {
            b[u]+=k*xx;
            fu=1;c[u]+=xx;
            update_t(u,k*xx);
        }
        else
            if ((u&1)==0 && (fu==1) && u+1!=v){
                b[u+1]+=k*xx;
                c[u+1]+=xx;
                update_t(u+1,k*xx);
            }
        //======================
        if ((v&1)==0 && !fv){
            b[v]+=k*xx;
            fv=1;
            c[v]+=xx;
            update_t(v,k*xx);
        }
        else
            if ((v&1)==1 && fv==1 && u+1!=v){
                b[v-1]+=k*xx;
                c[v-1]+=xx;
                update_t(v-1,k*xx);
            }
        k<<=1;
        u>>=1;
        v>>=1;
    }
    //===============================
    if (fu==0 && fv==0) {
        b[u]+=k*xx;
        c[u]+=xx;
        update_t(u,k*xx);
        return;
    }
    k>>=1;
    if (fu==0){
        b[2*u]+=k*xx;
        c[2*u]+=xx;
        update_t(u*2,k*xx);
        return;
    }
    if (fv==0){
        b[2*u+1]+=k*xx;
        c[2*u+1]+=xx;
        update_t(u*2+1,k*xx);
        return;
    }
    //for (int i=1; i<=4*n; i++) fo<<b[i]<<" ";fo<<endl;

}
void xuly1()
{
    int64_t tu=0,tv=0,res=0,u,v,u1,v1,slu,slv,sl;
    fi>>l>>r;
    u=nb+l-1; v=nb+r-1;
    tu=b[u];slu=1; slv=1; k=1; sl=l+r-1;
    if (u!=v) {
        tv=b[v];u1=u/2;v1=v/2;
      //  fo<<u<<" "<<v<<"*";
        while (u1!=v1){
            if (u%2==0) {
                slu+=k;
                tu+=b[u+1]+slu*c[u1];
            }
            else tu+=slu*c[u1];
            if ((v%2)==1){
                slv+=k;
                tv+=b[v-1]+slv*c[v1];
            }
            else  tv+=slv*c[v1];
            //fo<<u<<" "<<v<<"*";
            u=u1;v=v1;u1/=2; v1/=2; k=k*2;

        }
    }
    ///====================
   // fo<<u1<<"%";
    while (u1!=0){
        res+=sl*c[u1]; u1/=2;
    }
    res+=tu+tv;
   // fo<<res<<" "<<l<<" "<<r<<" "<<sl<<endl;

    double ans;
    ans=(double) res/(r-l+1);
    fo<<fixed<<setprecision(4)<<ans<<endl;

}
int main()
{ fi>>n>>q; --n;
    for (int i=20; i>=0; --i)
       if (((n>>i) &1) ) { nb=(1<<(i+1)) ; break;}
    for (int i=0; i<=n; i++){ int t; fi>>t; b[nb+i]=t; }
    for (int i=nb-1; i>=0; i--) b[i]=b[i*2]+b[i*2+1];
  //  for (int i=1; i<=4*n; i++) fo<<b[i]<<" ";fo<<endl;
    for (int i=1; i<=q; i++) {
        int loai;
        fi>>loai;
        //fo<<loai<<" ";
        if (loai==0) xuly1();
        else
            xuly2();
    }

}
