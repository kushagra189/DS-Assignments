#include <stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int given[100023]={0};
		int path[100023]={0};
		int path1[100023]={0};
		int path2[100023]={0};
		int ans[100023]={0};
		long long int low=-123456;
		long long int high=123456;
		int n;
		scanf("%d",&n);
		int i;
		for(i=0;i<n;i++)
		{
			scanf("%d",&given[i]);
		}
		int p;
		scanf("%d",&p);
		for(i=0;i<p;i++)
		{
			scanf("%d",&path[i]);
		}
		i=0;
		int k=0;
	//	while(given[i]!=path[0])
		while(i<n)
		{
			if(given[i]>low && given[i]<high)
			{
				if(given[i] == path[0])
				{
					path1[k++]=given[i];
					break;
				}
				if(given[i]>path[0])
				{
					path1[k++]=given[i];		
					high=given[i];
				}
				else if(given[i]<path[0])
				{
					path1[k++]=given[i];
					low=given[i];
				}
			}
			i++;
		}
		int j=0,l=0;
		low=-123456;
		high=123456;
	//	while(given[j]!=path[p-1])
		while(j<n)
		{
			if(given[j]>low && given[j]<high)
			{
				if(given[j] == path[p-1])
				{
					path2[l++]=given[j];
					break;
				}
				if(given[j]>path[p-1])
				{
					path2[l++]=given[j];
					high=given[j];
				}
				else if(given[j]<path[p-1])
				{
					path2[l++]=given[j];
					low=given[j];
				}
			}
			j++;
		}
		int o,b;
		/*for(o=0;o<k;o++)
		{
			printf("%d ",path1[o]);
		}
		printf("\n");
		for(o=0;o<l;o++)
		{
			printf("%d ",path2[o]);
		}
		printf("\n");*/
		if(l>k)
		{
			o=k;
			b=l;
		}
		else
		{
			o=l;
			b=k;
		}
		int z,index=0;
		for(z=0;z<o;z++)
		{
			if(path1[z]==path2[z])
			{
				index=z;
			}
		}
		int temp=0;
		for(i=k-1;i>=index;i--)
		{
			ans[temp]=path1[i];
			temp++;
		}
		for(i=index+1;i<l;i++)
		{
			ans[temp]=path2[i];
			temp++;
		}
		if(temp==p)
		{
			int flag=0;
			for(i=0;i<p;i++)
			{
				if(ans[i]==path[i])
				{
					flag=1;
				}
				else
				{
					flag=0;
					break;
				}
			}
			if(flag)
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
	}
	return 0;
}