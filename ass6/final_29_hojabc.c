#include <stdio.h>
#include <stdlib.h>

int* G[100023];
int count[100023]={0};
int deg[100023]={0};
int u[100023];
int v[100023];
int s[100023];
long long int dp1[100023]={0};
long long int dp2[100023]={0};

long long int max(long long int a,long long int b)
{
	return ((a>=b)?(a):(b));
}

void dfs(int u,int parent)
{
	int i;
	long long int s1=0,s2=0;
	for(i=0;i<count[u];i++)
	{
		if(G[u][i]==parent)
		{
			continue;
		}
		else
		{
			dfs(G[u][i],u);
			s1 = s1 + dp2[G[u][i]];
			s2 = s2 + max(dp1[G[u][i]],dp2[G[u][i]]);
		}
	}
	int r=s[u]+s1;
	dp1[u]=r;
	dp2[u]=s2;
	return;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}

	i=1;
	while(i<n)
	{
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++,deg[v[i]]++;
		i++;
	}

	i=1;
	while(i<=n)
	{
		G[i]=(int *)malloc(deg[i]*sizeof(int));
		i++;
	}
	i=1;
	while(i<n)
	{
		G[u[i]][count[u[i]]++]=v[i];
		G[v[i]][count[v[i]]++]=u[i];
		i++;
	}

	dfs(1,1);

	long long int ans = max(dp1[1],dp2[1]);
	printf("%lld\n",ans);
	return 0;
}
