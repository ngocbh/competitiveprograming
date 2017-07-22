#include<stdio.h>
#include<stdlib.h>

int n;
long a[2002],s[2002];
long w[2002][2002], f[2002][2002], k[2002][2002];

inline long Sum(int f, int t){
	return s[t]-s[f-1];
}

int main()
{   freopen("OPTCUT.inp","r",stdin);
	scanf("%d",&n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%ld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++) f[i][i]=0,k[i][i]=i;

	for(int l=2;l<=n;l++){

		for(int i=1,j=l;j<=n;i++,j++){

			f[i][j]=2000000000;

			for(int t=k[i][j-1];t<=k[i+1][j];t++){

				long v=Sum(i,j)+f[i][t-1]+f[t][j];

				if(v<f[i][j]) f[i][j]=v, k[i][j]=t;
			}
		}
	}
	printf("%ld\n",f[1][n]);
	system("PAUSE");
	return 0;
}

