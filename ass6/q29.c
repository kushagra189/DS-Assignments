#include <stdio.h>
int s[100023]={0};
int markup[100023]={0};
int markup1[100023]={0};
int main()
{
	int n;
	//int markup1[1000000000]={0};
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	long long int sum =0;
	for(i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(s[x]>s[y])
		{
			if(markup1[x]==0)
			{
				if(markup[x]==0)
				{
					sum+=s[x];
					markup[x]=1;
					markup1[x]=1;
				}
				else
				{
					if(markup[y]==0)
					{
						sum+=s[y];
						markup1[y]=1;
						markup[y]=1;
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				markup[y]=1;
				//continue;
			}
		}
		else
		{
			if(markup1[y]==0)
			{
				if(markup[y]==0)
				{
					sum+=s[y];
					markup[y]=1;
					markup1[y]=1;
				}
				else
				{
					if(markup[x]=0 && markup1[x]==0)
					{
						sum+=s[x];
						markup1[x]=1;
						markup[x]=1;
					}
					else
					{
						continue;
					}
				}
			}
			else
			{
				markup[x]=1;
			}
		}
	}
	printf("%lld\n",sum);
	return 0;
}