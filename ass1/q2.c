#include<stdio.h>
#include<string.h>

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



int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char a[n+2];
	int i,j,p;
	int b[n+2];
	scanf("%s",a);
	for(i=0;i<k;i++)
	{
		p=0;
		for(j=i;j<n;j+=k)
		{
			b[p]=a[j]-'0';
			p++;
		}
		merge(b,0,p-1);
		p--;
		for(j=i;j<n;j+=k)
		{
			a[j]=b[p]+'0';
			p--;
		}
	}
	printf("%s",a);
	printf("\n");
	return 0;
}
