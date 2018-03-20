#include<stdio.h>
long long int min(long long int a,long long int b)
{
	if(a>b)
		return b;
	else
		return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a=0,b=0,c=0;
	long long int store[1019]={0};
	store[0]=1;
	int k=1,p=n-1;
	while(p--)
	{
		long long int m=min(3*store[a],min(5*store[b],7*store[c]));
		if(3*store[a]==m)
		{
			store[k]=3*store[a];
			a++;
		}
		if(5*store[b]==m)
		{
			store[k]=5*store[b];
			b++;
		}
		if(7*store[c]==m)
		{
			store[k]=7*store[c];
			c++;
		}
		k++;
	}
	printf("%lld",store[n-1]);
	return 0;
}
