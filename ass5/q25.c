#include <stdio.h>
#include <math.h>

typedef struct node
{
	int a;
	int b;
	long long int dist;
}store;

void mergesort(store arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int i,j,k;
	store L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i].dist=arr[l+i].dist;
		L[i].a=arr[l+i].a;
		L[i].b=arr[l+i].b;
	}
	for(j=0;j<n2;j++)
	{
		R[j].dist=arr[j+m+1].dist;
		R[j].a=arr[j+m+1].a;
		R[j].b=arr[j+m+1].b;
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i].dist<=R[j].dist)
		{
			arr[k]=L[i];
			i++;
		}
		else
		{
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}
}

void merge(store arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge(arr,l,m);
		merge(arr,m+1,r);
		mergesort(arr,l,m,r);
	}
}

store array[1625];

int abso(int a,int b)
{
	if(a>b)
	{
		return (a-b);
	}
	else
	{
		return (b-a);
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int x,y;
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			array[i].a=x;
			array[i].b=y;
			array[i].dist=pow(x,2)+pow(y,2);
		}
		merge(array,0,n-1);
		/*for(i=0;i<n;i++)
		{
			printf("%lld %d %d\n",array[i].dist,array[i].a,array[i].b);
		}
		printf("\n");*/
		long long int sum=array[0].a+array[0].b;
		for(i=1;i<n;i++)
		{
			int p=abso(array[i].a,array[i-1].a);
			int q=abso(array[i].b,array[i-1].b);
			sum=sum+p+q;
		}
		printf("%lld\n",sum);
	}
	return 0;
}