#include <stdio.h>

int d[502][502];//={123456};
int u[200003];
int v[200003],w;

int max(int a,int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			d[i][j]=10000009;
		}	
	}
	for(i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w);
		if(d[u[i]][v[i]]==10000009)
		{
			d[u[i]][v[i]]=w;
			d[v[i]][u[i]]=w;
		}
		else
		{
			d[u[i]][v[i]]=max(w,d[u[i]][v[i]]);
			d[v[i]][u[i]]=max(w,d[v[i]][u[i]]);
		}
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==j)
				{
					d[i][j]=0;
				}
				else if(d[i][j]>d[i][k]+d[k][j])
				{
					d[i][j]=d[i][k]+d[k][j];
				}
			}
		}
	}
	long long int sum=0;
	for(i=1;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{	
			sum+=d[i][j];
			//printf("%d ",d[i][j]);
		}
		//printf("\n");
	}
	printf("%lld\n",2*sum);
	return 0;
}
