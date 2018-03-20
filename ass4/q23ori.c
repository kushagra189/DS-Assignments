#include <stdio.h>
#include <string.h>
#include <math.h>

long long int store_hash[123456]={0};
long long int reverse_hash[123456]={0};

int MOD=1000000321;

long long int power(int a,int b)
{
	long long int result=1;
	while(b)
	{
		if(b&1)
		{
			result*=a;
		}
		b>>=1;
		a*=a;
	}
	return result;
}

int main()
{
	int n,q,i;
	scanf("%d%d",&n,&q);
	char strinp[123456];
	scanf("%s",strinp);
	//int len=strlen(strinp);
	store_hash[0]=strinp[0]%MOD;
	reverse_hash[0]=strinp[n-1]%MOD;
	int len=0;
	for(i=1;i<n;i++)
	{
		store_hash[i]=((store_hash[i-1]*37)%MOD+strinp[i])%MOD;
		reverse_hash[i]=((reverse_hash[i-1]*37)%MOD+strinp[n-1-i])%MOD;
	}
	//printf("%lld %lld\n",store_hash[0],reverse_hash[0]);
	while(q--)
	{
		int k;
		scanf("%d",&k);
		int l[k],r[k];
		int i;
		long long int sum=0,reverse_sum=0;
		for(i=0;i<k;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			long long int val=((store_hash[r[i]-1]-store_hash[l[i]-2])*power(37,len))%MOD;
			len+=(r[i]-l[i]+1);
			sum=(sum+val)%MOD;
		}
		len=0;
		for(i=k-1;i>=0;i--)
		{
			long long int reverse_val=((reverse_hash[r[i]-1]-reverse_hash[l[i]-2])*power(37,len))%MOD;
			reverse_sum=(reverse_sum+reverse_val)%MOD;
			//reverse_sum+=(reverse_hash[n-r[i]-1]-reverse_hash[n-l[i]-2]);
			len+=(r[i]-l[i]+1);
		}
		printf("%lld %lld\n",sum,reverse_sum);
		if(sum==reverse_sum)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}