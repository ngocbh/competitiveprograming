#include <stdio.h>
#include <memory.h>

using namespace std;
int n,t,a[3000000];
void xuly(int n)
{   int nho=0,k=0;
    memset(a,0,sizeof(a));
    for (int i=2*n-1; i>=1; i--){
        if (i>n) --k;
        else ++k;
        a[i]=k+nho;
        nho=a[i]/10;
        a[i]=a[i]%10;

    }
    for (int i=1; i<=2*n-1; i++) printf("%d",a[i]); printf("\n");
}
int main()
{ scanf("%d",&t);

 for (int i=1; i<=t; i++){
    scanf("%d",&n);
    xuly(n);
 }
}
