#include <stdio.h>

typedef struct node
{
	int start;
	int end;
	int weight;
}edvt;

void mergesort(edvt arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int i,j,k;
	edvt L[n1],R[n2];
	for(i=0;i<n1;i++)
	{
		L[i].weight=arr[l+i].weight;
		L[i].start=arr[l+i].start;
		L[i].end=arr[l+i].end;
	}
	for(j=0;j<n2;j++)
	{
		R[j].weight=arr[j+m+1].weight;
		R[j].start=arr[j+m+1].start;
		R[j].end=arr[j+m+1].end;
	}
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i].weight<=R[j].weight)
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

void merge(edvt arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge(arr,l,m);
		merge(arr,m+1,r);
		mergesort(arr,l,m,r);
	}
}

edvt store[500040];

int find(int a[],int i)
{	
	if(a[i]==-1)
		return i;
	return find(a,a[i]);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		int b[n];
		scanf("%d%d",&n,&m);
		int i;
		for(i=0;i<n;i++)
		{
			b[i]=-1;
		}
		for(i=0;i<m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			store[i].start=x;
			store[i].end=y;
			store[i].weight=z;
		}
		merge(store,0,m-1);

		int c=0;
		i=0;
		long int sum=0;

		while(i<m)
		{
			if(c==n)
			{
				break;
			}
			else
			{
				//printf("%d\n",e[i].start.index);
				//printf("%d\n",e[i].end.index);
				
				int p=find(b,store[i].start);
				int q=find(b,store[i].end);

				//printf("%d %d\n",p,q);

				if(p!=q)
				{
					//union_vertex(b,p,q);
					b[p]=q;
					sum+=store[i].weight;
					i++;
					c++;
				}
				else
				{
					//continue;
					i++;
				}
			}
		}
		printf("%ld\n",sum);
	}
	return 0;
}
