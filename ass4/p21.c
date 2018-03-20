#include <stdio.h>
#include <string.h>

int s_array[123456];
char s[123456];

int main()
{
	scanf("%s",s);
	int i;
	int n=strlen(s);
	for(i=1;i<=n;i++)
	{
		s_array[i]=s[i-1]-'0';
	}

	int q;
	scanf("%d",&q);

	while(q--)
	{
		int p;
		scanf("%d",&p);
		if(p==1)
		{
			int pos,num;
			scanf("%d%d",&pos,&num);
			s_array[pos]=num;
		}
		else if(p==2)
		{
			int  a[10]={0},b[10]={0};
			int l1,l2,r1,r2;
			int flag=0;
			scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
			if((r1-l1)!=(r2-l2))
			{
				printf("NO\n");
			}
			else
			{
				for(i=l1;i<=r1;i++)
				{
					a[s_array[i]]++;
				}
				for(i=l2;i<=r2;i++)
				{
					b[s_array[i]]++;
				}/*
				for (int i = 0; i < 10; ++i)
				{
					printf("%d\n",a[i]);
				}
				printf("\n");

				for (int i = 0; i < 10; ++i)
				{
					printf("%d\n",b[i]);
				}*/
				//printf("\n");

				for(i=0;i<10;i++)
				{
					if(a[i]!=b[i])
					{
						//printf("gjh\n");
						flag=0;
						break;
					}
					else
					{
						flag=1;
					}
				}
				if(flag)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
		}
	}
	return 0;
}