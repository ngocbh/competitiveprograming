/*
Author : Priyank Bhatnagar.
*/
//{
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;
int gcd( int a, int b ) {  if( !b ) return a;  return gcd( b, a % b ); }

#define tr(container, it)for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

//}

/* Main code starts from here */

#define MAX 100100 // 10^5 + 100

int hs[MAX];
typedef pair<int , int> P;
stack< P > S;

int main()
{
	int n,t;
	scanf("%d",&t);
	while (t--){
	while(1)
	{
		scanf("%d",&n);
		if(!n) break;

		for(int i=0;i<n;i++)
		{
			scanf("%d",&hs[i]);
		}
		/* Enter the last bar of height '0', this will help us pop all the elements in the stack */
		hs[n]=0;
		long long best=0,temp;
		int start=0;

		for(int i=0;i<=n;i++)
		{
			start=i;
			while(!S.empty() && (hs[i] < S.top().second))
			{
				temp = (LL)(i - S.top().first ) * S.top().second;
				if(best < temp)
				{
					best = temp;
				}
				start=S.top().first;
				S.pop();
			}
			S.push(make_pair(start,hs[i]));
		}

		while(!S.empty())S.pop(); /* Clear Stack */

		printf("%lld\n",best);

	}}

}

