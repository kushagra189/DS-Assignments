#include<stdio.h>

void mergesort(long long int inp[],int left_index,int mid_index,int right_index)
{
	int n1=mid_index-left_index+1;
	int n2=right_index-mid_index;
	int i,j,k;
	long long int L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i]=inp[left_index+i];
	}
	for(j=0;j<n2;j++)
	{
		R[j]=inp[j+mid_index+1];
	}
	i=0;
	j=0;
	k=left_index;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			inp[k]=L[i];
			i++;
		}
		else
		{
			inp[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		inp[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		inp[k]=R[j];
		j++;
		k++;
	}
}

void merge(long long int inp[],int left_index,int right_index)
{
	if(left_index<right_index)
	{
		int mid_index=left_index+(right_index-left_index)/2;
		merge(inp,left_index,mid_index);
		merge(inp,mid_index+1,right_index);
		mergesort(inp,left_index,mid_index,right_index);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	long long int s[n],i,p[n],ans[n],j;
	for(i=0;i<n;i++)
	{
		scanf("%lld",&s[i]);
		p[i]=s[i];
	}
	merge(p,0,n-1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(p[i]==s[j])
			{
				ans[i]=j;
				break;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		merge(ans,0,i);
		for(j=0;j<i;j++)
		{
			printf("%lld ",ans[j]+1);
		}
		printf("%lld\n",ans[j]+1);
	}
	return 0;
}
