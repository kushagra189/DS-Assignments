#include<stdio.h>
void mergesort(int inp[],int left_index,int mid_index,int right_index)
{
	int n1=mid_index-left_index+1;
	int n2=right_index-mid_index;
	int i,j,k;
	int L[n1],R[n2];
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

void merge(int arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge(arr,l,m);
		merge(arr,m+1,r);
		mergesort(arr,l,m,r);
	}
}


int bin_search_upp_bound(int inp[],int low_index,int high_index,int num,int last)
{
	int ans=last;
	while(low_index<=high_index)
	{
		int mid_index=(low_index+high_index)/2;
		if(inp[mid_index]>num)
		{
			ans=mid_index;
			high_index=mid_index-1;
		}
		else
			low_index=mid_index+1;
	}
	return (ans);
}


int main()
{
	int n,i;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	int m;

	merge(a,0,n-1);

	scanf("%d",&m);
	while(m--)
	{
		int p;
		scanf("%d",&p);
		if(p==a[n-1])
			printf("0\n");
		else
			printf("%d\n",n-bin_search_upp_bound(a,0,n-1,p,n));
	}
	return 0;
}
