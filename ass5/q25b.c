#include <stdio.h>

typedef struct Node
{
	int index,x,y;
}vertex;

typedef struct node
{
	vertex start;
	vertex end;
	int weight;
}edge;

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

void mergesort(edge arr[],int l,int m,int r)
{
	int n1=m-l+1;
	int n2=r-m;
	int i,j,k;
	edge L[n1],R[n2];
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

void merge(edge arr[],int l,int r)
{
	if(l<r)
	{
		int m=l+(r-l)/2;
		merge(arr,l,m);
		merge(arr,m+1,r);
		mergesort(arr,l,m,r);
	}
}

int find(int a[],int i)
{	
	if(a[i]==-1)
		return i;
	return find(a,a[i]);
}

void union_vertex(int a[],int i,int j)
{
	a[j]=i;
}

vertex v[1539];
edge e[2254545];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		int b[2253],l;
		for (l=0;l<2253;l++)
			b[l]=-1;
		int i,x,y;
		v[0].x=0,v[0].y=0,v[0].index=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d%d",&x,&y);
			v[i].x=x;
			v[i].y=y;
			v[i].index=i;
		}

		int j,k=0;
		
		for(i=0;i<n+1;i++)
		{
			for(j=i+1;j<n+1;j++)
			{
				e[k].weight=abso(v[i].x,v[j].x)+abso(v[i].y,v[j].y);
				e[k].start=v[i];
				e[k].end=v[j];
				//printf("%d\n",e[k].weight );
				k++;
			}
		}

		merge(e,0,k-1);
//		for(i=0;i<k;i++)
//			printf("%d ",e[i].weight);
//printf("\n");
		int c=0;
		i=0;

		long int sum=0;

		while(i<k)
		{
			if(c==n)
			{
				break;
			}
			else
			{
				//printf("%d\n",e[i].start.index);
				//printf("%d\n",e[i].end.index);
				
				int p=find(b,e[i].start.index);
				int q=find(b,e[i].end.index);

				//printf("%d %d\n",p,q);

				if(p!=q)
				{
					//union_vertex(b,p,q);
					b[p]=q;
					sum+=e[i].weight;
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