#include <stdio.h>
#include <stdlib.h>

int* G[100023];
int count[100023]={0};
int vis[100023]={0};
int deg[100023]={0};
int u[100023];
int v[100023];
int s[100023];
int tree[100023];
int dp1[100023]={0};
int dp2[100023]={0};
int t=0;

int max(int a,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void dfs(int u)
{
	//printf("%d ",u);
	vis[u]=1;
	//tree[t++]=u;
	int i;
	int s1=0,s2=0;
	//int bc = u;
	for(i=0;i<count[u];i++)
	{
		if(vis[G[u][i]]!=1)
		{
			dfs(G[u][i]);
			s1+=dp2[G[u][i]];
			s2+=max(dp1[G[u][i]],dp2[G[u][i]]);
		}
	}
	dp1[u]=s[u]+s1;
	dp2[u]=s2;
}

int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}

	for(i=1;i<n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		deg[u[i]]++;
		deg[v[i]]++;
	}

	for(i=1;i<=n;i++)
	{
		G[i]=(int *)malloc(deg[i]*sizeof(int));
	}

	for(i=1;i<n;i++)
	{
		G[u[i]][count[u[i]]++]=v[i];
		G[v[i]][count[v[i]]++]=u[i];
	}
	//dfs(1);
	/*for(i=0;i<t;i++)
	{
		printf("%d ",tree[i]);
	}*/
	dfs(1);
	int ans = max(dp1[1],dp2[1]);
	printf("%d\n",ans);
	return 0;
}
